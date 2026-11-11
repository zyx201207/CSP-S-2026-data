#include<bits/stdc++.h>
using namespace std;
long long tttt,ttt,n,dd,a[1000000],d[1000000],ans,xx;
long long q[4000000],o[4000000],qq[4000000],oo[4000000];
long long zhaoo(long long l,long long r,long long x) {
	if(l>=r) return l;
	if(a[(l+r)/2]+dd>=x) return zhaoo(l,(l+r)/2,x);
	return zhaoo((l+r)/2+1,r,x);
}
void jian(long long l,long long r,long long x) {
	q[x]=999999999;
	o[x]=r-l+1;
	if(l==r) return ;
	jian(l,(l+r)/2,x<<1);
	jian((l+r)/2+1,r,x<<1|1);
	return ;
}
void gai(long long l,long long r,long long x,long long y,long long w,long long z) {
	if(l>y||r<y) return ;
	if(l==y&&r==y) {
		q[x]=w;
		o[x]=z;
		return ;
	}
	gai(l,(l+r)/2,x<<1,y,w,z);
	gai((l+r)/2+1,r,x<<1|1,y,w,z);
	q[x]=min(q[x<<1],q[x<<1|1]);
	o[x]=q[x<<1]>q[x<<1|1]?o[x<<1|1]:q[x<<1|1]>q[x<<1]?o[x<<1]:o[x<<1]+o[x<<1|1];
	return ;
}
void zhao(long long l,long long r,long long x,long long la,long long ra) {
	qq[x]=999999999,oo[x]=r-l+1;
	if(l>ra||r<la) return ;
//	printf("#%d %d %d %d\n",l,r,la,ra);
	if(l>=la&&r<=ra) {
		qq[x]=q[x];
		oo[x]=o[x];
		return ;
	}
	zhao(l,(l+r)/2,x<<1,la,ra);
	zhao((l+r)/2+1,r,x<<1|1,la,ra);
	qq[x]=min(qq[x<<1],qq[x<<1|1]);
	oo[x]=qq[x<<1]>qq[x<<1|1]?oo[x<<1|1]:qq[x<<1|1]>qq[x<<1]?oo[x<<1]:oo[x<<1]+oo[x<<1|1];
	return ;
}
long long read() {
	long long xxxx=0,ffff=1;
	char cccc=getchar();
	while(cccc<'0'||cccc>'9') {
		if(cccc=='-') ffff=-1;
		cccc=getchar();
	}
	while(cccc>='0'&&cccc<='9') {
		xxxx=xxxx*10+cccc-'0';
		cccc=getchar();
	}
	return xxxx*ffff;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>tttt>>ttt;
	while(ttt--) {
		cin>>n>>dd;
		for(long long i=1; i<=n; i++) a[i]=read();
		ans=0;
		if(n<=2) {
			printf("0\n");
			continue;
		}
		if(n<=5000) {
			for(long long i=1; i<=n; i++) {
				jian(1,n,1);
				gai(1,n,1,i,0,1);
				for(long long j=i+1; j<=n; j++) {
					if(a[j-1]+dd>=a[j]) {
						xx=zhaoo(i,j-1,a[j]);
						zhao(1,n,1,xx,j-1);
						if(oo[1]==2) ans++;
						gai(1,n,1,j,qq[1]+1,oo[1]);
					} else break;
				}
			}
		} else if(tttt==11||tttt==12) {
			xx=dd/(a[2]-a[1]);
			if(xx>1) ans=max((long long)0,n-2*xx+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
