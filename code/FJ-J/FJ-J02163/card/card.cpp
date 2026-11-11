#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],b[N],ans[N],mp[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(mp,-1,sizeof(mp));
		int r=0;
		for(int j=i;j<=n;j++){
			if(mp[a[j]]>0){
				r=mp[a[j]]-1;
			}
			b[++r]=a[j];
			mp[a[j]]=r;
		}
		for(int j=1;j<=r;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
