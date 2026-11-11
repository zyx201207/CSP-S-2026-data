#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],vis[300005],cnt,now[500005],ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int o=1;o<=n;o++){
		memset(vis,0,sizeof(vis));
		cnt=0;
		for(int i=o;i<=n;i++){
			if(!vis[a[i]]){
				now[++cnt]=a[i];
				vis[a[i]]=cnt;
			}
			else{
				for(int j=vis[a[i]]+1;j<=cnt;j++) vis[now[j]]=0;
				cnt=vis[a[i]]-1;
				now[++cnt]=a[i];
				vis[a[i]]=cnt;
			}
		}
		for(int i=1;i<=m;i++) if(vis[i]) ans[i]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
