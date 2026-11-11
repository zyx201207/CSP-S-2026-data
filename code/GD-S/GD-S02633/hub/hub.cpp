#include <bits/stdc++.h>

//#define int ll
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define pb push_back
#define endl "\n"

using namespace std;

const int N=4000;
const int inf=1e7;

int c,t;

int n,k;
vector<int>q[N+5];
int cnt=-1;

int fa[N+5];
int find(int g){
	while(g!=fa[g]) g=fa[g]=fa[fa[g]];
	return g;
}

int dit[N+5][N+5];
void csh(){
	queue<pr>t;
	bitset<N+5> vis; 
	for(int i=1;i<=n;i++){
		t.push(mp(i,0));
		for(int j=1;j<=n;j++) vis[j]=0;
		while(!t.empty()){
			pr mq=t.front();
			t.pop();
			if(vis[mq.first]==1) continue;
			vis[mq.first]=1;
			dit[i][mq.first]=mq.second;
			for(int ne:q[mq.first]){
				if(vis[ne]==0) t.push(mp(ne,mq.second+1));
			}
		}
	}
}

bool vis[N+5];
vector<int>s;

bool check(){
	for(int i:s) for(int j:q[i]) if(vis[j]==1) fa[find(i)]=fa[find(j)];
	map<int,bool>flag;
	int fg=0;
	for(int i:s){
		if(flag[find(i)]==false) fg++;
		flag[find(i)]=true;
	}
	for(int i=1;i<=n;i++) {fa[i]=i;}
	return (fg<=2);
}

int da=inf;

void dfs(int mq){
	if(s.size()==k){
		if(check()==true){
			int sum=0;
			for(int i=1;i<=n;i++){
				int tim=inf;
				if(vis[i]==false){
					for(int j:s){
						tim=min(tim,dit[i][j]);
					}
					sum=max(sum,tim);
				}
				
			}
			da=min(da,sum);
		} 
		return ;
	}
	for(int i=mq+1;i<=n;i++){
		s.pb(i);
		vis[i]=true;
		dfs(i);
		s.pop_back();
		vis[i]=false;
	}
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) {q[i].clear();vis[i]=0;fa[i]=i;}
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		q[a].pb(b);
		q[b].pb(a);
	}
	csh();
	da=inf;
	s.clear();
	dfs(0);
	cout<<da<<endl;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
//20pts
