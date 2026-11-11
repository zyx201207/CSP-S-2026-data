#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5,M=5e5+5;
int n,m,a[N],sum=0,ans=0,dp[N],vis[5005],b[5005],da[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
		int cnt=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]>0){
				for(int k=vis[a[j]]+1;k<=cnt;k++){
					vis[b[k]]=0;
				}
				cnt=vis[a[j]];
			}
			else{
				b[++cnt]=a[j];
				vis[a[j]]=cnt;
			}
		}
		for(int j=1;j<=cnt;j++){
			da[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<da[i]<<' ';
	}
	return 0;
}
