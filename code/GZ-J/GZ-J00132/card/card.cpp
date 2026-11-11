//蒋木铮 GZ-J00132 贵阳第一中学 
#include<bits/stdc++.h>
using namespace std;
const int N=5090;
int a[N],vis[N],n,m,g[N],vis1[N],use[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0&&use[j]==0) g[++cnt]=a[j],vis[a[j]]=cnt;
			else {
				for(int k=vis[a[j]];k<=n;k++) {
					if(g[k]!=0) use[k]=1;
					g[k]=0;
				}
				cnt=vis[a[j]];
				g[cnt]=a[j];
			}
		}
		for(int j=1;j<=n;j++)  vis1[g[j]]++;
		
		memset(g,0,sizeof(g));
		memset(vis,0,sizeof(vis));
		memset(use,0,sizeof(use));
	}
	for(int i=1;i<=m;i++) cout<<vis1[i]<<" ";
	return 0;
}
