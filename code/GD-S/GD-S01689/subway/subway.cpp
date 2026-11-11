#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,mn=1e18;
int w[500005];
int k[505];
int a[505][1005],t[505][1005];
vector<int>g[1005];
bool f[1005][1005];
vector<int>l[1005];
bool f1[505][1005];
bool f2[1005][1005];
void dfs(int u,int v,int s,int pos){
	if(u==v){
		mn=min(mn,pos);
		return;
	}
	f[s][u]=true;
	for(auto c:g[u]){
		if(f1[s][c]==true){
			for(auto h:l[c]){
				if((!f[h][u]||!f[h][c])&&!f2[c][u]){
					f[h][c]=true;
					f[h][u]=true;
					f2[u][c]=true;
					dfs(c,v,h,pos+t[s][u]+t[s][c]);
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][a[i][j]];
			for(int s=1;s<j;s++){
				g[a[i][s]].push_back(a[i][j]);
				g[a[i][j]].push_back(a[i][s]);
			}
			l[a[i][j]].push_back(i);
			f1[i][a[i][j]]=true;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		mn=1e18;
		for(auto h:l[x]){
			memset(f,false,sizeof(f));
			dfs(x,y,h,0);
		}
		cout<<mn+w[x]+w[y]<<endl;
	}
	return 0;
}
