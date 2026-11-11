#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
const int N=2e6+5;
int x[N],pre[N],nxt[N];
int fa[N],siz[N];
int p[N];
vector<int>v[N];
//vector<vector<vector<int> > >c;
int find(int x){
	if(fa[x]!=x)	fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int x,int y){
	int u=find(x),v=find(y);
	if(u==v)	return;
	if(siz[u]<siz[v])	swap(u,v);
	fa[v]=u;
	siz[u]+=siz[v];
}
int C;
void solve(){
	unordered_map<int,int>um;
//	c=vector<vector<vector<int> > >();
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		v[i]=vector<int>();
		
		cin>>x[i];
		fa[i]=i,siz[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(x[i]+d>=x[n])	nxt[i]=n; 
		else	
			nxt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			
		if(x[i]-d<=x[1])	pre[i]=1; 
		else	
			pre[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
	}
	for(int i=1;i<=n;i++){
		if(pre[nxt[i]]==i)	merge(i,nxt[i]);
	}
	
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(siz[fa[i]]>1){
			if(!um.count(fa[i]))	um[fa[i]]=++cnt;
			p[i]=v[um[fa[i]]].size();
			v[um[fa[i]]].push_back(i);	
		}	
	}
	vector<vector<vector< pair<int,int> > > >c(cnt+5,vector<vector< pair<int,int> > >(cnt+5) );
	for(int i=1;i<=cnt;i++){
		for(int j=0;j<v[i].size()-1;j++){
//			cout<<v[i][j]<<" "<<fa[v[i][j]-1]<<" "<<fa[v[i][j]+1]<<'\n';
//			if(v[i][j]<n&&siz[fa[v[i][j]+1]]>1&&v[i][j]+1!=v[fa[v[i][j]+1]][0])	{
//				c[i][um[fa[v[i][j]+1]]].push_back({j,p[v[i][j]+1]});
//				c[um[fa[v[i][j]+1]]][i].push_back({p[v[i][j]+1],j});
//			}
			if(v[i][j]<n&&siz[fa[v[i][j]+1]]>1&&v[i][j]+1!=v[um[fa[v[i][j]+1]]][0])	{
//				c[i][um[fa[v[i][j]+1]]].push_back({j,p[v[i][j]+1]});
				c[um[fa[v[i][j]+1]]][i].push_back({p[v[i][j]+1],j});
			}
		
		
		}
//		cout<<'\n';
	}
	
	ll ans=0;
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			
			for(int k=0;k<c[i][j].size();k++){
//				cout<<c[i][j][k].first<<" "<<c[i][j][k].second<<'\n';
				ans+=(c[i][j][k].first-(k>0?c[i][j][k-1].first:0))*
				((k<c[i][j].size()-1?c[i][j][k+1].second:v[j].size()-1)-c[i][j][k].second);
//				cout<<ans<<" "<<(c[i][j][k].first-(k>0?c[i][j][k-1].first:0))<<" ";
//				cout<<((k<c[i][j].size()-1?c[i][j][k+1].second:v[j].size()-1)-c[i][j][k].second)<<'\n';
			}
//			cout<<'\n';
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>C>>t;
	while(t--)
		solve();
	
	
	return 0;
}
