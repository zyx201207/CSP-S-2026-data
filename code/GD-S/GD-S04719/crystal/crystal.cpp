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
const int N = 5e5 + 5;
int n,M,a[N],pr[N],ans=1;
void work(){
	n=in(),M=in();
	_rep(i,1,n) a[i]=in();
	sort(a+1,a+1+n);
	_rep(i,1,n) pr[i] = pr[i-1]+a[i];
	_rep(i,1,n){
		int l = 1, r = i, res = 0;
//		cout << i << endl;
		while(l<=r){
			int m = (l + r) >> 1, len = i-m+1;
//			cout << "m = " << m << " " << a[i]*len - (pr[i]-pr[m-1]) << endl;
			if(a[i]*len-(pr[i]-pr[m-1])<=M) res = len, r = m-1;
			else l = m + 1;
		}
		ans = max(ans,res);
	}
	out(ans);
}
/*
5 8
-3 -1 2 2 7

*/
signed main(){
//	FRR("crystal4.in");
//	FRW("mine.txt");
	FRR("crystal.in");
	FRW("crystal.out");
	int T = 1;
	while(T--){
		work();
	}
	return 0;
}
// predict : AC

