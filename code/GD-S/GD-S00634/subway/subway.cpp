#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define freop(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define endl '\n'
#define inf ((ll)1e16)
#define lb(x) ((x)&-(x))
#define pil pair<int,ll>
#define fir first
#define sec second
#define mkp make_pair
const int N=5e5+5,M=505,Q=1e5+5;
int C,n,m,d,q,k[M],st[Q],ed[Q];
ll w[N],dis[M][M],ans[Q];
vector<int> a[M];
vector<pil> t[N],q1[M],q2[M];

inline ll gett(int u,int x){
	auto y=lower_bound(t[u].begin(),t[u].end(),mkp(x,0ll));
	if(y==t[u].end()) cerr << "Error\n";
	return (y!=t[u].end()?(*y).sec:inf);
}

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	cout.tie(0);
	freop("subway");
//↑以上为初始化↑
//-------------------------------------------------
	cin >> C >> m >> n >> d >> q;
	for(int i = 1;i<=n;++i) cin >> w[i];
	for(int i = 1;i<=m;++i){
		for(int j = 1;j<=m;++j) dis[i][j]=inf;
		cin >> k[i],a[i].resize(k[i]);
		for(int j = 0,tt;j<k[i];++j){
			cin >> a[i][j] >> tt;
			t[a[i][j]].push_back(mkp(i,tt));
		}
		sort(a[i].begin(),a[i].end());
	}
	for(int i = 1;i<=n;++i){
		sort(t[i].begin(),t[i].end());
		int x,tx,y,ty;
		for(pil it1:t[i]){
			tie(x,tx)=it1;
			for(pil it2:t[i]){
				tie(y,ty)=it2;
				if(x==y) continue;
				if(tx+ty<dis[x][y])
					dis[x][y]=dis[y][x]=tx+ty;
			}
		}
	}
	for(int z = 1;z<=m;++z){
		dis[z][z]=0;
		for(int x = 1;x<=m;++x)
			for(int y = 1;y<=m;++y)
				if(dis[x][y]>dis[x][z]+dis[z][y])
					dis[x][y]=dis[y][x]=dis[x][z]+dis[z][y];
	}
	for(int i = 1;i<=q;++i){
		cin >> st[i] >> ed[i],ans[i]=inf;
		for(pil it:t[st[i]])
			q1[it.fir].emplace_back(mkp(i,gett(st[i],it.fir)));
		for(pil it:t[ed[i]])
			q2[it.fir].emplace_back(mkp(i,gett(ed[i],it.fir)));
	}
	for(int i = 1;i<=m;++i)
		for(int j = 1;j<=m;++j){
			auto l=q1[i].begin(),r=q2[j].begin();
			int x,y,tu,tv;
			while(l!=q1[i].end()&&r!=q2[j].end()){
				tie(x,tu)=*l,tie(y,tv)=*r;
				if(x==y) ans[x]=min(ans[x],dis[i][j]+tu+tv);
				(x<=y?++l:++r);
			}
		}
	for(int i = 1;i<=q;++i)
		cout << ans[i]+w[st[i]]+w[ed[i]] << endl;
	return 0;
}

