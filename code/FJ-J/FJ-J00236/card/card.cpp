#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],vis[500005],p[500005],sum[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(p,0,sizeof(p));
		int k=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				p[++k]=a[j];
				vis[a[j]]=k;
			}else{
				int u=k;
				k=vis[a[j]];
				for(int y=k;y<=u;y++) p[y]=0;
				p[k]=a[j];
			}
		}
		for(int j=1;j<=k;j++) sum[p[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
}
