#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e2+5,M=5e5+5;
int c,n,m,d,q;
int ww[M];
int k[N];
int t[M][N];
vector<int> a[N],b[M];
unordered_map<int,ll> mp[M];
bool vis[M];

ll bfs(int st,int ed){
	memset(vis,0,sizeof vis);
	queue<pair<int,ll>> q;
	q.push({st,0});
	while(!q.empty()){
		auto x=q.front();
		int u=x.first;
		ll w=x.second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		
		vector<int> stt;
		for(int r:b[u]){
			for(int v:a[r]){
				ll tmp=mp[u][v],s=t[u][r]+t[v][r];
				if(!tmp) mp[u][v]=mp[v][u]=s;
				else mp[u][v]=mp[v][u]=min(tmp,s);
				stt.push_back(v);
			}
		}
		//cout<<u<<"aaa"<<'\n';
		for(int v:stt){
			ll tmp=mp[st][v],s=w+mp[u][v];
			if(!tmp) mp[st][v]=mp[v][st]=s;
			else mp[st][v]=mp[v][st]=min(tmp,s);
			if(mp[v][ed]){
				ll ttmp=mp[st][ed];
				s=mp[st][v]+mp[v][ed];
				//cout<<"bbb "<<v<<' '<<s<<'\n';
				if(!ttmp) mp[st][ed]=mp[ed][st]=s;
				else mp[st][ed]=mp[ed][st]=min(ttmp,s);
			}else if(!vis[v]){
				q.push({v,s});
				//cout<<v<<' '<<w<<' '<<s<<'\n';
			}
		}
	}
	return mp[st][ed];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>ww[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[x][i]=y;
			b[x].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=bfs(x,y)+ww[x]+ww[y];
		cout<<ans<<'\n';
	}
	return 0;
} 
