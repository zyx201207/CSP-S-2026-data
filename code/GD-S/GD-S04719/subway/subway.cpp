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
const int M = 5e5 + 5, N = 505;
int c,n,m,d,q,w[M],f[N],cnt[N];
vector <pint> s[M];
vector <pint> h[N];
vector <pint> H[N];
void work(){
	c=in(),n=in(),m=in(),d=in(),q=in();
	_rep(i,1,m) w[i] = in();
	// m station through <= d
	// n way <=500
	_rep(i,1,n){
		cnt[i] = in();
		_rep(j,1,cnt[i]){
			int x=in(),cost=in();
			s[x].pb(mp(i,cost));
			h[i].pb(mp(x,cost));
		}
	}
	_rep(i,1,n){
		for(pint j:h[i]){
			int w1 = j.snd, v = j.fst;
			for(pint jj:s[v]){
				int vv = jj.fst, w2 = jj.snd;
				if(vv!=i){
					H[i].pb(mp(vv,w1+w2));
				}
			}
		}
	}
	while(q--){
		int x=in(),y=in(),ans1=w[x]+w[y];
		_rep(i,1,n) f[i] = -1;
		priority_queue <pint,vector<pint>,greater<pint> > q;
		for(pint i:s[x]){
			f[i.fst] = i.snd;
			q.push(mp(i.snd,i.fst));
		}
		while(!q.empty()){
			int u = q.top().snd;
//			cout << "u = " << u << endl;
			q.pop();
			for(pint i:H[u]){
				int v = i.fst, w = i.snd;
				if(f[v] == -1 || (f[v]!=-1&&f[v]>f[u]+w)){
					f[v] = f[u] + w;
//					cout << "update " << u << " -> " << vv << " " << f[vv] << endl;
//					cout << f[u] << " " << w << " " << ww << endl;
					q.push(mp(f[v],v));
				}
			}
		}
		int all = -1;
		for(pint i:s[y]){
			int v = i.fst, w = i.snd;
			int now = f[v] + w;
//			cout << "way " << v << "include " << y << " " << f[v] << " " << w << endl; 
			if(all == -1) all = now + ans1;
			else all = min(all,now+ans1);
		}
//		cout << "ans = ";
		out(all),pc('\n');
	}
}
signed main(){
//	system("fc mine.txt subway7.ans");
//	return 0;
//	FRR("subway7.in");
//	FRW("mine.txt"); 
//	FRW("subway.out");
	FRR("subway.in");
	FRW("subway.out"); 
	int T = 1;
	while(T--){
		work();
	}
	return 0;
}
// predict :: AC

