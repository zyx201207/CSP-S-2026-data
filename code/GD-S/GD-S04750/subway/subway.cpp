#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
int c,n,m,d,q;
struct node{
	int a,b;
};
vector<int>v[N][N];
//int num[N]; 
int w[N];
vector<node>v1[N];
int a[N][N];
int t[N][N];
int vis[N];
int ans=1e9+7;
void dfs(int l,int now,int e,int tz){
//	cout<<now<<endl;
	if(now==e){
		ans=min(ans,tz);
//		cout<<ans<<endl;
		return ;
	}for(int i=1;i<=2;i++){
		if(i==1){
			for(auto j:v[l][now]){
				if(!vis[j]){
					vis[j]=1;
					dfs(l,j,e,tz);
					vis[j]=0;
				}
			}
		}else{
			for(auto j:v1[now]){
//				int g=v[j.a][now];
				if(j.a!=l){
					dfs(j.a,now,e,tz+t[l][now]+t[j.a][now]);
				}
			}
		}
	}
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j]; 
			v[i][a[i][j]].push_back(a[i][j-1]);
			v[i][a[i][j-1]].push_back(a[i][j]);
			v1[a[i][j]].push_back({i,j});
		}
	}
	while(q--){
		ans=1e9+7;
		int x,y;
		memset(vis,0,sizeof(vis));
		cin>>x>>y;
		for(auto i:v1[x]){
			dfs(i.a,x,y,w[x]);
		}
		cout<<ans+w[y]<<"\n";
	}
	return 0;
}

