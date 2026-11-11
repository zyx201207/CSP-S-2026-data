#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mn=5e5,mm=3e5;
const int maxn=mn+10,maxm=mm+10;
int n,m,a[maxn],b[maxn],ans[maxm],num[maxm];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int l=1;l<=n;l++){
		for(int i=l;i<=n;i++)a[i]=b[i];
		for(int i=1;i<=m;i++)num[i]=0;
		for(int i=l;i<=n;i++){
			if(num[a[i]]>0)
				for(int j=i-1;j>=l;j--){
					if(a[j]==a[i]){num[a[i]]--,a[j]=-1;break;}
					if(a[j]!=-1)num[a[j]]--,a[j]=-1;
				}
			num[a[i]]++;
		}for(int i=1;i<=m;i++)if(num[i]>0)ans[i]++;
	}for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
