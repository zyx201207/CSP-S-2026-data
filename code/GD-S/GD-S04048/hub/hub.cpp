#include<bits/stdc++.h>
using namespace std;
long long tttt,ttt,n,m,h[2000000],t[2000000],g[2000000],cnt;
long long b[2000000],s,ss,sa[2000000],sb[2000000],ans;
long long xx,yy,zz,ww;
struct bian {
	long long x,y;
} e[4000000];
void jia(long long x,long long y) {
	e[++cnt].x=h[x];
	e[cnt].y=y;
	h[x]=cnt;
	return ;
}
void dp(long long x,long long y,long long z) {
	sa[x]=1;
	sb[x]=0;
	for(long long i=h[x]; i; i=e[i].x) {
		if(e[i].y!=y&&g[e[i].y]>z) {
			dp(e[i].y,x,z);
			sa[x]+=sa[e[i].y];
			sb[x]++;
		}
	}
//	printf("#@%lld %lld %lld %lld\n",x,y,sa[x],sb[x]);
	if(sb[x]==0) {
		yy=max(yy,sa[x]-1);
	}
	return ;
}
void pp(long long x,long long y,long long z) {
	if(y==0||sb[x]==1) ww++;
	else return ;
	for(long long i=h[x]; i; i=e[i].x) {
		if(e[i].y!=y&&g[e[i].y]>z&&sb[e[i].y]==1){
			pp(e[i].y,x,z);
		}
	}
	return ;
}
bool pd(long long x) {
	xx=0;
	for(long long i=1; i<=n; i++) {
		if(g[i]>x) xx++;
	}
//	printf("##%lld %lld\n",x,xx);
	if(xx<=m) return 1;
	yy=0;
	for(long long i=1; i<=n; i++) {
		if(g[i]==zz) {
			dp(i,0,x);
			ww=0;
			if(sb[i]==2) pp(i,0,x);
			yy=max(yy,ww);
			break;
		}
	}
//	printf("@@%lld %lld\n",x,yy);
	return (xx-yy<=m);
}
long long zhao(long long l,long long r) {
	if(l>=r) return l;
	if(pd((l+r)/2)) return zhao(l,(l+r)/2);
	return zhao((l+r)/2+1,r);
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>tttt>>ttt;
	while(ttt--) {
		cin>>n>>m;
		cnt=0;
		for(long long i=0; i<=n+1; i++) h[i]=t[i]=g[i]=0;
		for(long long i=1; i<n; i++) {
			cin>>xx>>yy;
			jia(xx,yy);
			jia(yy,xx);
			t[xx]++;
			t[yy]++;
		}
		s=ss=0;
		for(long long i=1; i<=n; i++) if(t[i]==1) b[++s]=i;
		xx=yy=1;
		while(xx<=s) {
			ss=0;
			for(xx; xx<=s; xx++) {
				g[b[xx]]=yy;
				for(long long i=h[b[xx]]; i; i=e[i].x) {
					t[e[i].y]--;
					if(t[e[i].y]==1) b[(++ss)+s]=e[i].y;
				}
			}
			yy++;
			s+=ss;
		}
		zz=yy-1;
		ans=zhao(1,n);
		printf("%lld\n",ans);
	}
	return 0;
}
