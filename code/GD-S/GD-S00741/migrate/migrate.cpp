#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=b;--i)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define int long long
typedef std::pair<int,int> pii;
const int INF = 0x3f3f3f3f;
const int MAXN = (int)2e6+10;

int read(){
	int x=0,f=1;char c = getchar();
	for(;!isdigit(c);c=getchar()) if(c == '-') f = -1;
	for(;isdigit(c);c=getchar()) x = (x<<3)+(x<<1)+(c^48);
	return x*f;
} 
template<typename T>
void write(T x){
	if(x<0){putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void IO(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
}

int c,T,n,d,cnt,ans,x[MAXN];

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

signed main(){
	IO();
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		FOR(i,0,n) cin>>x[i];
		ans = 0;
		cnt = d/(x[1]-x[0]);
		if((c==11||c==12)&&cnt>1) ans = max(n-cnt*2+1,0);
		cout<<ans<<'\n';
	} 
	return 0;
}

