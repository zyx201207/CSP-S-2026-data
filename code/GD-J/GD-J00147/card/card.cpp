#include<bits/stdc++.h>
#define int long long
#define stp(x) fixed<<setprecision(x)
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N],b[M],ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)b[j]=0;
		int t=0;
		for(int j=i;j<=n;j++){
			if(!b[a[j]])b[a[j]]=++t;
			else{
				for(int k=1;k<=m;k++)if(b[k]>b[a[j]])t--,b[k]=0;
			}
		}
		for(int j=1;j<=m;j++)if(b[j])ans[j]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}
