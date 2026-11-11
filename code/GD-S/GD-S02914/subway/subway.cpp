	#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int c,n,m,d,q;
int w[N];
int k,a[N],t[N];
int x,y;
struct T{
	int ww,tt;
}g[N];
int fa[N];
int ans;
int vis[N];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		g[i].ww=w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			g[a[j]].tt=t[j];
			if(j>=2){
				fa[a[j]]=a[j-1];
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int vv=y;
		int cnt=0;
		memset(vis,0,sizeof(vis));
		vis[++cnt]=y;
		while(1){
			if(fa[vv]==x){
				cnt++;
				vis[cnt]=x;
				break;
			}else{
				vv=fa[vv];
				cnt++;
				vis[cnt]=vv;
			}
		}
		int ans=0;
		for(int j=cnt;j>=1;j--){
			if(j==cnt){
				ans+=g[j].ww;
			}else{
				ans+=g[j].ww;
				ans+=g[j].tt;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
