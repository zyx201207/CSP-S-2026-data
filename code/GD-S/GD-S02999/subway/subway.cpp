#include <bits/stdc++.h>
using namespace std;
namespace IO{
	const int BUFSIZE = 1<<20;
	char inBUF[BUFSIZE], *p1, *p2, c;
	char outBUF[BUFSIZE];
	int o1;
	stack<char> st;
	typedef long long ll;
	ll tep,fl;
	inline char getchar(){
		if (p1 == p2)	p2 = (p1 = inBUF) + fread(inBUF,1,BUFSIZE,stdin);
		return p1 == p2 ? EOF : *p1++; 
	}
	inline ll readll(){
		tep = 0, fl = 1;
		while ((c^'-') && (c < '0' || c > '9'))	c = getchar();
		if (c == '-')	fl = -1, c = getchar();
		while ('0' <= c && c <= '9')	tep = tep*10+c-'0', c = getchar();
		return tep*fl;
	}
	inline void flush(){
		fwrite(outBUF,1,o1,stdout);
		o1 = 0;
	}
	inline void putchar(char ct){
		if (o1 == BUFSIZE)	flush();
		outBUF[o1++] = ct;
	}
	inline void putll(ll x){
		if (x < 0)	putchar('-'), x = -x;
		while (x){
			st.push(x%10+'0');
			x /= 10;
		}
		while (!st.empty()){
			putchar(st.top());
			st.pop();
		}
	}
}
#define in(s) freopen(#s ".in","r",stdin)
#define out(s) freopen(#s ".out","w",stdout)
#define int long long
typedef pair<int,int> pii;
const int N = 5e2+5, M = 5e5+5, inf = 0x3f3f3f3f3f3f3f3f;

int C,n,m,d,Q;
int arr[M];
vector<pii> brc[M];
int tol,u,v;
int val[N][N];
int a,b;
vector<pii> vec[N];
priority_queue<pii,vector<pii>,greater<pii> > que;
int dis[N][N];
pii tep;
int ans;

signed main(){
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	in(subway);
	out(subway);
	memset(val,0x3f,sizeof(val));
	memset(dis,0x3f,sizeof(dis));
//	scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&d,&Q);
//	cin >> C >> n >> m >> d >> Q;
	C = IO::readll(), n = IO::readll(), m = IO::readll(), d = IO::readll(), Q = IO::readll(); 
//	for(int i=1;i<=m;i++)	scanf("%lld",&arr[i]);
//	for(int i=1;i<=m;i++)	cin >> arr[i];
	for(int i=1;i<=m;i++)	arr[i] = IO::readll();
	for(int i=1;i<=n;i++){
//		scanf("%lld",&tol);
//		cin >> tol;
		tol = IO::readll();
		for(int j=1;j<=tol;j++){
//			scanf("%lld%lld",&u,&v);
//			cin >> u >> v;
			u = IO::readll(), v = IO::readll();
			brc[u].push_back({i,v});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto j:brc[i]){
			for(auto k:brc[i]){
				a = j.first, b = k.first;
				if (a == b)	continue;
				val[a][b] = min(val[a][b],j.second+k.second);
				val[b][a] = min(val[b][a],j.second+k.second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if (i == j)	continue;
			if (val[i][j]^inf)	vec[i].push_back({j,val[i][j]});
		}
	}
	for(int k=1;k<=n;k++){
		que.push({0,k});
		dis[k][k] = 0;
		while (!que.empty()){
			tep = que.top(), que.pop();
			if (tep.first > dis[k][tep.second])	continue;
			for(auto i:vec[tep.second]){
				if (i.second+tep.first < dis[k][i.first]){
					dis[k][i.first] = i.second+tep.first;
					que.push({dis[k][i.first],i.first});
				}
			}
		}
	}
	while (Q--){
		ans = inf;
//		scanf("%lld%lld",&u,&v);
//		cin >> u >> v;
		u = IO::readll(), v = IO::readll();
		for(auto fr:brc[u]){
			for(auto ed:brc[v]){
				ans = min(ans,dis[fr.first][ed.first]+fr.second+ed.second);
			}
		}
//		printf("%lld\n",ans+arr[u]+arr[v]);
//		cout << ans+arr[u]+arr[v] << "\n";
		IO::putll(ans+arr[u]+arr[v]);
		IO::putchar('\n');
	}
//	cout << endl;
	IO::flush();
//	while (1);
	return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/

