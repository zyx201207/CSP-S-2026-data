#include<bits/stdc++.h>
#define il inline
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
#define vpii vector<pii>
#define pb push_back
#define mst(a,x) memset(a,x,sizeof a)
using namespace std;
const int N=2e6+10,INF=0x3f3f3f3f;
int n,C;
ll d,a[N];
namespace sol1 {
	void sol() {
		int as=0;
		for(int i=1;i<=n;i++) {
			int ct=0,ls=0,lls=0;
			for(int j=i+1;j<=n;j++) {
				if(a[j]-a[j-1]>d) break;
				int ps=max(i,ls);
				if(a[j]-a[ps]>d) {
					if(ls&&a[j-1]-a[ls-1]<=d) {
						ct++;
						if(ls>i+1&&a[j-1]-a[ls-2]<=d) break;
						if(lls&&a[ls-1]-a[lls-1]<=d) break;
					}
					lls=ls,ls=j-1;
				}
				int tmp=ct;
				if(ls&&a[j]-a[ls-1]<=d) {
					tmp++;
					if(ls>i+1&&a[j]-a[ls-2]<=d) tmp++;
					if(lls&&a[ls-1]-a[lls-1]<=d) tmp++;
				}
//				if(i==1&&j==4) printf("%d %d %d\n",tmp,ls,ps);
				if(tmp==1) {
					as++;
					printf("%d %d\n",i,j);
				}
			}
		}
//		cerr<<n<<" "<<d<<"\n";
//		for(int i=1;i<=n;i++) cerr<<a[i]<<" "; cerr<<"\n";
		printf("%d\n",as);
	}
}
int ps[N],F[N],S[N],ln[N],tt[N],LN[N],TT[N],rt[N];
void QwQ() {
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	if(n<=5000) return sol1::sol();
	for(int i=1,j=1;i<=n;i++) {
		while(j<=n&&a[j]-a[i]<=d) j++;
		ps[i]=j-1;
	}
	for(int i=1;i<=n;i++) F[i]=S[i]=ln[i]=tt[i]=LN[i]=TT[i]=rt[i]=0;
	for(int i=n;i;i--) if(ps[i]!=i) {
		F[i]=F[ps[i]],S[i]=S[ps[i]],rt[i]=rt[ps[i]];
		if(i>1&&a[i]-a[i-1]<=d) {
			if(a[ps[i]]-a[i-1]<=d) {
				S[i]=F[i],F[i]=i;
				if(i>2&&a[ps[i]]-a[i-2]<=d) S[i]=i;
			}
			int x=ps[i],bn=x;
			if(a[ps[i]-1]-a[i-1]<=d&&ps[ps[i]]!=ps[i]) {
				if(a[ps[x]]-a[x-1]<=d) {
					if(!F[i]||F[i]>i) F[i]=i;
					if(!S[i]||S[i]>i) S[i]=i;
				} else if(a[x]-a[x-1]<=d) bn=ps[x-1];
			}
//			if(i==5) printf("%d\n",bn);
			int cr;
			if(i>2) cr=ps[i-1]-max(i,ps[i-2]);
			else cr=ps[i-1]-i;
			ln[i]=cr;
			tt[i]=ps[i]-ps[i-1];
//			if(i==3) printf("%d %d\n",ln[i],tt[i]);
			int l=max(bn,x>2?ps[x-2]:0),r=ps[x-1];
			LN[i]=LN[ps[i]]+max(r-l,0);
			TT[i]=TT[ps[i]]+ps[x]-ps[x-1];
//			if(i==3) printf("%d %d %d %d\n",max(r-l,0),ps[x]-ps[x-1],LN[i],TT[i]);
//			if(i==6) printf("%d\n",TT[i]);
//			if(i==8) printf("%d\n",TT[i]);
		} else LN[i]=LN[ps[i]],TT[i]=TT[ps[i]];
	} else rt[i]=i;
	ll as=0;
	for(int i=1;i<=n;i++) if(ps[i]!=i) {
		int x=F[ps[i]],y=S[ps[i]];
		if(!x) as+=LN[ps[i]];
		else if(!y) {
			as+=LN[ps[i]]-LN[x];
			as+=TT[x];
		} else {
			as+=LN[ps[i]]-LN[x];
			as+=TT[x]-TT[y];
		}
//		printf("%d\n",as);
		if(ps[ps[i]]!=ps[i]) as+=ln[ps[i]];
//		printf("%d %d %d %lld\n",ps[i],x,y,as);
	}
	printf("%lld\n",as);
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1;
	scanf("%d%d",&C,&T);
	while(T--) QwQ();
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
6 3
0 1 2 3 4 7

0 1
10 22
0 7 14 21 28 35 42 49 56 63

0 1
10 14
-31 -24 -17 -10 -3 4 11 18 25 32

0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983


i->to[i] 建出森林 
找到第一个第二个断点F,S
(to[i],F]取区间 
(F,S]取后缀 
(i,to[i]] and (S,root]没救了 

调了两小时我是大区! 
*/
