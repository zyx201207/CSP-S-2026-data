#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=2e6+7;
int c,t;
int n,k;
vector<int> g[N];
int fa[N];
int a[N];
int dis[4000][4000];
int ans=21368732;
set<pii> p;
int find(int x){
	return x==fa[x]?x:fa[x]==find(fa[x]);
}
void merge(int a,int b){
	fa[find(a)]=fa[find(b)];
}
bool check(){
	set<int> s;
	for(int i=1;i<=k;i++){
		s.insert(a[i]);
	}
	if((int)s.size()!=k)	return false;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		for(int j=i+1;j<=k;j++){
			if(p.find({a[i],a[j]})!=p.end()){
				if(find(a[i])!=find(a[j])){
					merge(a[i],a[j]);
				}
			}
		}
	}
	int c=0;
	for(int i=1;i<=k;i++){
		if(a[i]==fa[a[i]])	c++;
	}
	if(c>2)	return false;
	return true;
}
void dfs(int x){
	if(x>k){
		if(check()){
			set<int> s;
			for(int i=1;i<=k;i++){
				s.insert(a[i]);
			}
			int dnt=0;
			for(int i=1;i<=n;i++){
				if(s.find(i)==s.end()){
					int cnt=32123123;
					for(int j=1;j<=k;j++){
						cnt=min(cnt,dis[i][a[j]]);
					}
					dnt=max(dnt,cnt);
				}
			}
			ans=min(ans,dnt);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		a[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		p.clear();
		ans=21368732;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			p.insert({u,v});
			p.insert({v,u});
		}
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
		}
		for(auto x:p){
			dis[x.first][x.second]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}

