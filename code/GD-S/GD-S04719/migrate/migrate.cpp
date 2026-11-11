#include <bits/stdc++.h>
using namespace std;

#define int long long
//#ifdef __linux__
//#define gc getchar_unlocked
//#define pc putchar_unlocked
//#else
#define pc putchar
#define gc getchar
//#endif
#define pint pair<int,int>
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define i128 __int128
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for(int i=(a);i<=(b);c)
#define _rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for(int i=(a);i>=(b);c)
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)

int in(){
	int x=0,y=1,a=gc();
	while(a<'0'||a>'9'){
		if(a==EOF) return 0;
		if(a=='-') y=-1;a=gc();
	}
	while(a>='0'&&a<='9') x=x*10+a-'0',a=gc();
	return x*y;
}
void out(int x){
	if(x<0)pc('-'),x=-x;
	if(x>9) out(x/10);
	pc('0'+x%10);
}
const int N = 2e6 + 5;
int c,x[N],dis[305][305],n,d,ans;
map <pint,int> m;
void dfs(int st,int y,int sum){
	dis[st][y] = min(dis[st][y],sum);
	for(int i=y+1;i<=n;i++){
		if(x[i]-x[y]<=d){
			dfs(st,i,sum+1);
		}
	}
}
void dfs1(int st,int y,int sum){
	if(sum == dis[st][y] && st != y) m[mp(st,y)]++;
	for(int i=y+1;i<=n;i++){
		if(x[i]-x[y]<=d){
			dfs1(st,i,sum+1);
		}
	}
}
void work(){
	n = in(), d = in();
	_rep(i,1,n) x[i] = in();
	if(x[n]-x[1]<=d){
		out(0),pc('\n');
		return;
	}
//	if(c == 1 || c == 2){
		_rep(i,1,n){
			_rep(j,1,n){
				dis[i][j] = 1e18;
			}
		}
		ans = 0;
		_rep(i,1,n){
			dfs(i,i,0);
		}
		_rep(i,1,n){
			dfs1(i,i,0);
		}
		_rep(i,1,n){
			_rep(j,1,n){
				if(m[mp(i,j)] == 2) ans++;
			}
		}
		out(ans),pc('\n');
		m.clear();
		return;
//	}
	if(c==13||c==14){
		
		return;
	}
	if(c == 11 || c== 12){
		
		
		return;
	}
}
signed main(){
//	FRR("migrate4.in");
	FRR("migrate.in");
	FRW("migrate.out");
	c = in(); int T = in();
	while(T--){
		work();
	}
	return 0;
}
// predict :: 10 pts
