#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#define int long long
using namespace std;
const int maxm=5e5+5,maxn=505;
int c,n,m,d,q,ans=(int)INT_MAX;
bool vis[maxn];
int w[maxm];
vector<pair<int,int>> rout[maxn],plat[maxm];
vector<int> E[maxn];
int read(){
	char ch;
	int n=0,f=1;
	ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar_unlocked()){
		if(ch=='-'){
			f=-1;
		}
	}
	for(;ch>='0'&&ch<='9';ch=getchar_unlocked()){
		n=(n<<3)+(n<<1)+(ch^48);
	}
	return f*n;
}
void solve1(){
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			int a,t;
			cin>>a>>t;
			rout[i].push_back(make_pair(a,t));
			plat[a].push_back(make_pair(i,t));
		}
	}
	while(q--) {
		ans=(int)INT_MAX;
		memset(vis,0,sizeof(vis));
		int x,y;
		cin>>x>>y;

		cout<<ans<<endl;
	}
}
void solve(int x,int y,int cnt) {
	if(x==y) {
		ans=min(ans,cnt);
		return ;
	}
	if(cnt>=ans) {
		return ;
	}
	for(auto it:plat[x]) {
		int ro=it.first;
		int t=it.second;
		for(auto v:rout[ro]) {
			if(v.first!=x&&!vis[v.first]) {
				vis[v.first]=1;
				solve(v.first,y,cnt+t+v.second);
				vis[v.first]=0;
			}
		}
	}
	return ;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>c>>n>>m>>d>>q;
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
//	if(c>=7&&c<=11){
//		solve1();
//		return 0;
//	}
	for(int i=1; i<=m; i++) {
//		cin>>w[i];
		w[i]=read();
	}
	for(int i=1; i<=n; i++) {
		int k;
//		cin>>k;
		k=read();
		for(int j=1; j<=k; j++) {
			int a,t;
//			cin>>a>>t;
			a=read();
			t=read();
			rout[i].push_back(make_pair(a,t));
			plat[a].push_back(make_pair(i,t));
		}
	}
	while(q--) {
		ans=(int)INT_MAX;
		memset(vis,0,sizeof(vis));
		int x,y;
//		cin>>x>>y;
		x=read();
		y=read();
		solve(x,y,w[x]+w[y]);
		cout<<ans<<endl;
	}
	return 0;
}
