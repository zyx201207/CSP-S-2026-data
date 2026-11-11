#include<bits/stdc++.h>//ccfºÃÍæÂð 
std::string acdegf="subway2",acdegftmp;
using namespace std;
inline long long read() {
	register long long wx=0,f=1;
//	scanf("%lld",&wx);

	register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))wx=(wx<<3)+(wx<<1)+(ch^48),ch=getchar();
	return wx*f;
}
long long c,m,n,d,q,w[500005],d_[500005],k[1005],x,y,dp[1005][1005];
vector<long long> a[1005],t[1005];
vector<pair<long long,long long> >l[500005];
void solve() {
	memset(dp,0x3f,sizeof dp);
	swap(n,m);
	for(int i=1; i<=n; ++i)cin>>w[i];
	for(int i=1; i<=m; ++i) {
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1; j<=k[i]; ++j) {
			scanf("%lld",&a[i][0]);
			scanf("%lld",&t[i][0]);
			a[i].push_back(a[i][0]);
			t[i].push_back(t[i][0]);
		}
		for(int j=1; j<=k[i]; ++j) {
			for(int p=1;p<=k[i];++p){
			
				dp[a[i][p]][a[i][j]]=dp[a[i][p]][a[i][j]]=min(dp[a[i][p]][a[i][j]],t[i][p]+t[i][j]);
				
			}
		}
		dp[i][i]=0;
	}
	for(int k=1; k<=n; ++k) {
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) {
				if(dp[i][k]+dp[k][j]<dp[i][j])dp[i][j]=dp[i][k]+dp[k][j];
			}
		}
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int i=1;i<=q;++i){
		cin>>x>>y;
		cout<<dp[x][y]+w[x]+w[y]<<'\n';
	}
}
void solve2() {
	memset(dp,0x3f,sizeof dp);
	
	for(int i=1; i<=m; ++i)cin>>w[i];
	for(int i=1; i<=n; ++i) {
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1; j<=k[i]; ++j) {
			a[i][0]=read();
			t[i][0]=read();
			if(d_[a[i][0]]==0)l[a[i][0]].push_back(make_pair(0,0));
//			cout<<a[i][0]<<' '<<i<<' '<<t[i][0]<<'\n';
			l[a[i][0]].push_back(make_pair(i,t[i][0]));
			int t=l[a[i][0]][(int)(l[a[i][0]].size()-1)].first;
//			cout<<a[i][0]<<' '<<(l[a[i][0]].size()-1)<<' '<<l[a[i][0]][(int)(l[a[i][0]].size()-1)].first<<' '<<l[a[i][0]][l[a[i][0]].size()-1].second<<'\n';
			++d_[a[i][0]];
		}
		dp[i][i]=0;
	}
//	cout<<1<<'\n';
	for(int i=1;i<=m;++i){
		for(int j=1;j<=d_[i];++j){
			for(int p=1;p<=d_[i];++p){
//				cout<<d_[i]<<' '<<i<<' '<<j<<' '<<p<<' '<<l[i][j].first<<' '<<l[i][p].first<<' '<<dp[l[i][j].first][l[i][p].first]<<' '<<l[i][j].second+l[i][p].second<<'\n';'
				dp[l[i][j].first][l[i][p].first]=min(dp[l[i][j].first][l[i][p].first],l[i][j].second+l[i][p].second);
			}
		}
//		cout<<'\n';
	}
//	cout<<1<<'\n';
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int p=1; p<=n; ++p) {
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) {
//				cout<<i<<' '<<
				if(dp[i][p]+dp[p][j]<dp[i][j])dp[i][j]=dp[i][p]+dp[p][j];
			}
		}
	}
//	cout<<1<<'\n';
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int i=1;i<=q;++i){
		x=read();
		y=read();
		long long ans=1e15;
		for(int j=1;j<=d_[x];++j){
			for(int p=1;p<=d_[y];++p){
				ans=min(ans,dp[l[x][j].first][l[y][p].first]+l[x][j].second+l[y][p].second);
//				cout<<ans<<' '<<l[x][j].first<<' '<<l[y][p].first<<' '<<l[x][j].second<<' '<<l[y][p].second<<'\n';
			}
		}
		
		cout<<ans+w[x]+w[y]<<'\n';
	}
//	cout<<1<<'\n';
}
int main(){
	acdegftmp=acdegf+".in";
	freopen(acdegftmp.c_str(),"r",stdin);
//	acdegftmp=acdegf+".out";
//	freopen(acdegftmp.c_str(),"w",stdout);
	cin>>c>>n>>m>>d>>q;
//	if(c<=11)solve();
//	else
	solve2();
}
