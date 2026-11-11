#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

const int N=5005;
const int inf=1e9;

int dis[N][N],n,tag[N][N];
ll d,x[N]; 
int c,T;
ll ans=0;

void solve() {
	scanf("%d%lld",&n,&d);
	rep(i,1,n) scanf("%lld",x+i);
	if(n==1) {
		printf("0\n");
		return ;
	}
	ans=0;
	rep(i,1,n) rep(j,1,n) dis[i][j]=inf,tag[i][j]=0;
	int stp=1;
	rep(i,1,n) {
		int lp=i;
		while(lp>0 and x[i]-x[lp]<=d) lp--;
		lp++;
		if(lp==i) stp=i;
		dis[i][i]=0;
		for(int j=i-1;j>=stp;j--) {
			if(j>=lp) {
				dis[i][j]=tag[i][j]=1;
				continue;
			}
			dis[i][j]=dis[lp][j]+1;
			int pt1=0,pt2=0,fl=1;
			for(int k=i;k>=max(j+1,lp);k--) {
				if(dis[k][j]+1!=dis[i][j]) continue;
				if(tag[k][j]==1) pt1++;
				else if(tag[k][j]==2) pt2++;
				else fl=0;
			}
			if(!fl) tag[i][j]=0;
			else if((pt1==2 and pt2==0) or (pt1==0 and pt2==1))
				tag[i][j]=2,ans++;
			else if(pt1==1 and pt2==0)
				tag[i][j]=1;
		}
	}
	printf("%lld\n",ans);
	return ;
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--) solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
