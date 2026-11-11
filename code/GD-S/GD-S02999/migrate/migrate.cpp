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
const int N = 2e6+5, inf = 0x3f3f3f3f3f3f3f3f;

int C,T;
int n,m;
int arr[N];
int ans;
int dis[N];
int crr[N];

inline void mian(){
	ans = 0;
//	scanf("%lld%lld",&n,&m);
//	cin >> n >> m;
	n = IO::readll(), m = IO::readll();
//	for(int i=1;i<=n;i++)	scanf("%lld",&arr[i]);
//	for(int i=1;i<=n;i++)	cin >> arr[i];
	for(int i=1;i<=n;i++)	arr[i] = IO::readll();
	for(int i=1;i<=n;i++){
		int fr = i, s = 0;
		for(int j=i;j<=n;j++)	crr[j] = 0, dis[j] = inf;
		dis[i] = 0;
		crr[i]++, crr[i+1]--;
		for(int j=i;j<=n;j++){
			if (dis[j] == inf)	continue;
			int ind = upper_bound(arr+j,arr+n+1,arr[j]+m)-arr-1;
			while (fr < ind)	dis[++fr] = dis[j]+1;
			int jnd = lower_bound(dis+j,dis+n+1,dis[j]+1)-dis;
			s += crr[j];
			crr[jnd] += s, crr[ind+1] -= s;
			ans += s == 2;
		}
	}
//	printf("%lld\n",ans);
	cout << ans << "\n";
}

inline void mcan(){
//	cin >> n >> m;
	n = IO::readll(), m = IO::readll();
	ans = 0;
//	for(int i=1;i<=n;i++)	cin >> arr[i];
	for(int i=1;i<=n;i++)	arr[i] = IO::readll();
	if (n == 1){
		cout << 0 << '\n';
		return;
	}
	int c = arr[2]-arr[1];
	if (m < 2*c){
		cout << 0 << '\n';
		return;
	}
	if (m/c*2 >= n){
		cout << 0 << '\n';
		return;
	}
//	cout << n << ' ' << m << ' ' << c << '\n';
//	cout << floor(m*1.0/c) << ' ' << ceil(2.0*m/c) << '\n';
//	long double fr = m*1.0/c, ed = 2.0*m/c;
//	for(int i=floor(fr)+1;i<ed;i++){
//		ans += n-i;
//	} 
//	ans += n-ceil(ed)+1;
//	ans += n-ceil(ed)+2;
	ans += n-(m/c)*2+1;
	cout << ans << '\n';
}

inline void mkan(){
	ans = 0;
	n = IO::readll(), m = IO::readll();
	for(int i=1;i<=n;i++)	arr[i] = IO::readll();
	for(int i=1;i<=n;i++){
		
	}
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	in(migrate);
	out(migrate);
//	cin >> C >> T;
	C = IO::readll(), T = IO::readll();
//	scanf("%lld%lld",&C,&T);
	if (1 <= C && C <= 10){
		while (T--)	mian();
		cout << endl;
	}else if (11 <= C && C <= 12){
		while (T--)	mcan();
		cout << endl;
	}else{
		while (T--)	mian();
		cout << endl;
	}
	return 0;
}

/*

11 2
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63

0 1
10 3
0 3 6 7 8 9 10 11 14 17

1 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
6 2
-4 -3 -2 -1 3 6

11 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
