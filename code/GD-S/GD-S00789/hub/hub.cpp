#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define out() (cout<<"sb\n")
#define vector basic_string

const int N=1e6+5,M=1e3+5;

bool beg;
int n,k,dep[N],md[N],siz[N];
int f[M][M][2][4],now;
vector<int> G[N]; 

inline void clean(){
	;
}

void dfs1(int u,int p){
	dep[u]=dep[p]+1,md[u]=0,siz[u]=1;
	for(int &v:G[u]){
		if(v==p) continue;
		dfs1(v,u);
		md[u]=max(md[u],md[v]+1);
		siz[u]+=siz[v];
	}
}

 

void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		G[u]+=v,G[v]+=u;
	}
	dfs1(1,0);
	memset(f,0x3f,sizeof(f));
	cout<<(n-k)/2<<"\n";
}

bool en;

signed main(){
//	system("fc .in .ans");
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	cerr<<((&en)-(&beg))/1048576.0<<"\n";
	IOS;
	int T;
	cin>>T>>T;
	while(T--) solve(),clean();
	
	return 0;
}

