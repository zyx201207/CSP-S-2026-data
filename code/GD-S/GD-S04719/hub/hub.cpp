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
const int N = 1e6 + 5;
int c,n,k,ans;
vector <int> e[N];
bool ck[15],vi[15];int dis[15][15];
int dis1[N];
void dfs1(int u){
	vi[u] = 1;
	for(int v:e[u]){
		if(vi[v] == 0 && ck[v]){
			dfs1(v);
		}
	}
}
void dfs2(int be,int u,int fa,int depth){
	dis[be][u] = depth;
	for(int v:e[u]){
		if(v!=fa) dfs2(be,v,u,depth+1);
	}
}
void dfs(int x,int cnt){
	if(x == n+1){
		if(cnt!=k) return;
		_rep(i,1,n) vi[i] = 0;
		int num = 0;
		_rep(i,1,n){
			if(vi[i] == 0 && ck[i]){
				num++;
				dfs1(i);
			}
		}
		_rep(i,1,n){
			dfs2(i,i,0,0);
		}
		int now = 0;
		if(num<=2){
			_rep(i,1,n){
				if(ck[i] == 1) continue;
				vector <int> all;
				_rep(j,1,n) if(ck[j]) all.pb(j);
				int cur = dis[i][all[0]];
				for(int j=1;j<all.size();++j){
					cur = min(cur,dis[i][all[j]]);
				}
				now = max(now,cur);
			}
			ans = min(ans,now);
		}
		return;
	}
	if(n-x>=k-cnt){
		ck[x] = 0;
		dfs(x+1,cnt);
	}
	if(cnt+1<=k){
		ck[x] = 1, dfs(x+1,cnt+1);
	}
}
void dfs3(int u,int depth){
	dis1[u] = depth; 
	for(int v:e[u]){
		if(dis1[v]<depth+1){
			dfs3(v,depth+1);
		}
	}
}
void work(){
	ans = 1e18;
	n=in(),k=in();
	_rep(i,1,n-1){
		int u=in(),v=in();
		e[u].pb(v),e[v].pb(u);
	}
	if(n<=10){
		dfs(1,0);
		out(ans),pc('\n'); 
	}else{
		if(k == 2){
			_rep(i,1,n){
				_rep(j,1,n) dis1[i] = 1e18;
				dfs3(i,0);
				_rep(j,1,n){
					dfs3(j,0);
					int cur = 0;
					_rep(k,1,n) cur = max(cur,dis1[k]);
					ans = min(ans,cur);
				}
			}
			out(ans),pc('\n');
		}else{
			;
		}
	}
	_rep(i,1,n) e[i].clear();
}
/*
0 1
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
*/
signed main(){
//	FRR("hub2.in");
	FRR("hub.in");
	FRW("hub.out");
	c = in();
	int T = in();
	while(T--){
		work();
	}
	return 0;
}
// predict :: 15 pts

