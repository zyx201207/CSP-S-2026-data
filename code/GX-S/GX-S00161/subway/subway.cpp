#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,l,r,ans,cnt,minn;
long long a[114514],k[514514];
long long b[10086][10086];
long long jisuan(long long x,long long y,long long z) {
	if(z>=minn) {
		return -1;
	}
	if(b[x][y]==r) {
		return z;
	}
	if(x==l&&z>ans) {
		return -1;
	}
	if(y>2*k[x]||x>n) {
		return -1;
	}
	jisuan(x+1,y,z+b[x][y+1]);
	jisuan(x,y+2,z+b[x][y+1]);
	jisuan(x+1,y,z);
	jisuan(x,y+2,z);
	return -1;
}
void shuru() {
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++) {
		scanf("%lld",&a[i]);
	}
	for(long long i=1;i<=n;i++) {
		scanf("%lld",&k[i]);
		for(long long j=1;j<=2*k[i];j++) {
			scanf("%lld",&b[i][j]);
		}
	}
	for(long long i=1;i<=q;i++) {
		scanf("%lld%lld",&l,&r);
		ans=a[l]+a[r];
		minn=1145141;
		cnt=jisuan(1,1,ans);
		if(cnt<minn&&cnt>=0) {
			minn=cnt;
		}
		if(i!=q) {
			printf("%lld\n",minn);
		} else {
			printf("%lld",minn);
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	shuru();
	return 0;
}
