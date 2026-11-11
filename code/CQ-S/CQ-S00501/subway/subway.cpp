//100 at 15:02
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PIL pair<int,ll>
#define PLI pair<ll,int>
#define fi first
#define se second 
using ll=long long;
using ull=unsigned long long;
using ld=long double;
#define FILE "subway"
// #define FOR_ONLINE
// #define TEST_FOR_MS
// #define freopen(x) feropen(x)
bool mst;
const int N=505,M=5e5+5,D=25;
ll c,n,m,d,q,w[M];
ll dis[N][N];
vector<PIL>to[M];
void Main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)   cin>>w[i];
	for(int i=1,x,a,t;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++)   cin>>a>>t,to[a].push_back({i,t});
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)   dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto x:to[i]){
			for(auto y:to[i])   dis[x.fi][y.fi]=min(dis[x.fi][y.fi],x.se+y.se);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)   dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	for(int i=1,s,t;i<=q;i++){
		cin>>s>>t;ll ans=0x3f3f3f3f3f3f3f3f;
		for(auto x:to[s]){
			for(auto y:to[t])   ans=min(ans,dis[x.fi][y.fi]+x.se+y.se+w[s]+w[t]);
		}
		cout<<ans<<"\n";
	}
}
bool med;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
#ifndef FOR_ONLINE
#ifndef TEST_FOR_MS
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
#else
	string x;cin>>x;
	freopen(("down/"FILE"/"FILE+x+".in").c_str(),"r",stdin);
	freopen(FILE".out","w",stdout);
#endif
#endif
	cerr<<fixed<<setprecision(6)<<abs(&med-&mst)/1024.0/1024<<"MB\n";
	double st=clock();
	Main();
	cerr<<fixed<<setprecision(6)<<(clock()-st)/CLOCKS_PER_SEC<<"s\n";
}
/*
WorldMachine suki

11.4 是我的生日，整理迷惑行为大赏的能祝我生日快乐吗

许愿世界机器可以天天开心啊
*/