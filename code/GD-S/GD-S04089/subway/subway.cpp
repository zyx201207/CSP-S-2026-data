#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,sz[505],n,m,d,q,f[505][505],a[500005];
struct nd{
	int v,w;
};
vector<nd> t[500005];
//map<int,int> g[505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		cin>>sz[i];
		for (int j=1;j<=sz[i];j++){
			int v,w;
			cin>>v>>w;
			t[v].push_back(nd{i,w});
		}
	}
	memset(f,0x3f,sizeof(f));
	for (int i=1;i<=m;i++){
		for (int j=0;j<t[i].size();j++){
			for (int k=j;k<t[i].size();k++){
				int ux=t[i][j].v,vx=t[i][k].v,uw=t[i][j].w,vw=t[i][k].w;
				if (ux==vx){
					f[ux][vx]=0;
				}else{
					f[ux][vx]=f[vx][ux]=min(f[ux][vx],uw+vw);
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			for (int k=1;k<=n;k++){
				f[j][k]=min(f[j][k],f[j][i]+f[i][k]); 
			}
		}
	}
	while (q--){
		int ans=114514191981010086ll,u,v;
		cin>>u>>v;
		for (auto i:t[u]){
			for (auto j:t[v]){
				ans=min(ans,a[u]+i.w+f[i.v][j.v]+j.w+a[v]);
			}
		}
		cout<<ans<<endl;
	}
} 
