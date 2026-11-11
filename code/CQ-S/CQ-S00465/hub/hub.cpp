#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;
const int N=2e6+5;
bool bbb;
ll c,t,n,k,fa[N][22],dep[N],ans,tong[N],f[N];
vector<ll> v[N];
PII e[N];
void fast(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return;
}
void dfs(ll x,ll fath){
	fa[x][0]=fath;dep[x]=dep[fath]+1;
	for(int i=1;i<22;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(auto i:v[x]){
		if(i==fath) continue;
		dfs(i,x);
	} 
	return;
}
ll lca(ll x,ll y){
	if(x==y) return x;
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=21;i>=0;i--) if(dep[fa[y][i]]>=dep[x]) y=fa[y][i];
	if(x==y) return x;
	for(int i=21;i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0]; 
}
ll find(ll x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool eee;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//cerr<<abs(&bbb-&eee)/1024.0/1024.0<<endl;
	fast();
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=n-1;i++){
			ll x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
			e[i]={x,y};
		}
		dfs(1,0);
		ans=inf;
		for(int s=0;s<(1<<n);s++){	
			ll cnt=0;
			for(int i=1;i<=n;i++) if((s>>i-1)&1) cnt++;
			if(cnt!=k) continue;
			for(int i=1;i<=n;i++) tong[i]=0,f[i]=i;
			for(int i=1;i<=n-1;i++){
				if(((s>>e[i].first-1)&1)==0||((s>>e[i].second-1)&1)==0) continue;
				if(find(e[i].first)==find(e[i].second)) continue;
				f[find(e[i].first)]=find(e[i].second);
			}
			cnt=0;
			for(int i=1;i<=n;i++){
				if(((s>>i-1)&1)==0) continue;
				if(tong[find(i)]==0){
					tong[find(i)]=1;
					cnt++; 
				}				
			}

			if(cnt>2) continue;
			ll res=0; 
			for(int i=1;i<=n;i++){
				if((s>>i-1)&1) continue;
				ll mi=inf; 
				for(int j=1;j<=n;j++){
					if(((s>>j-1)&1)==0) continue;
					mi=min(mi,dep[i]-1+dep[j]-1-2*dep[lca(i,j)]+2);
				}
				res=max(res,mi);
			}
			ans=min(ans,res);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
