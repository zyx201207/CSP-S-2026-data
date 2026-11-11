#include<bits/stdc++.h>
using namespace std;
long long ttt,n,m,dd,qq,wa[1000000],xx,yy,zz;
long long h[1000000],ct,ans;
long long d[1000000],f[501][20005],ff[3][500005];
long long cnt,a[1000000],b[1000000],t,tt;
bool bz[1000000];
struct bian {
	long long x,y,z;
} e[3000000];
void jiab(long long x,long long y,long long z) {
	e[++ct].x=h[x];
	e[ct].y=y;
	e[ct].z=z;
	h[x]=ct;
	return ;
}
void jia(long long x,long long y) {
	a[++cnt]=x;
	b[cnt]=y;
	t=cnt;
	while(t>1) {
		if(a[t]>=a[t>>1]) break;
		swap(a[t],a[t>>1]);
		swap(b[t],b[t>>1]);
		t>>=1;
	}
	return ;
}
void jian() {
	a[1]=a[cnt];
	b[1]=b[cnt];
	a[cnt]=b[cnt]=0;
	cnt--;
	t=1;
	while((t<<1)<=cnt) {
		tt=(t<<1);
		if((tt|1)<=cnt&&a[tt|1]<a[tt]) tt|=1;
		if(a[t]<=a[tt]) break;
		swap(a[t],a[tt]);
		swap(b[t],b[tt]);
		t=tt;
	}
	return ;
}
void dij(long long x,long long y) {
	bz[x]=1;
	f[y][x]=d[x];
	for(long long i=h[x]; i; i=e[i].x) {
		if(d[e[i].y]>d[x]+e[i].z) {
			d[e[i].y]=d[x]+e[i].z;
			jia(d[e[i].y],e[i].y);
		}
	}
	while(cnt&&bz[b[1]]==1) jian();
	if(cnt) dij(b[1],y);
	return ;
}
void dijf(long long x,long long y) {
	bz[x]=1;
	ff[y][x]=d[x];
	for(long long i=h[x]; i; i=e[i].x) {
		if(d[e[i].y]>d[x]+e[i].z) {
			d[e[i].y]=d[x]+e[i].z;
			jia(d[e[i].y],e[i].y);
		}
	}
	while(cnt&&bz[b[1]]==1) jian();
	if(cnt) dijf(b[1],y);
	return ;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ttt>>n>>m>>dd>>qq;
	for(long long i=1; i<=m; i++) cin>>wa[i];
	for(long long i=1; i<=n; i++) {
		cin>>zz;
		for(long long j=1; j<=zz; j++) {
			cin>>xx>>yy;
			jiab(xx,i+m,yy);
			jiab(i+m,xx,yy);
		}
	}
	if(n<=2) {
		for(long long i=1; i<=n; i++) {
			for(long long j=1; j<=m+n; j++) bz[j]=0,d[j]=99999999999999999;
			while(cnt>0) jian();
			d[i+m]=0;
			dijf(i+m,i);
		}
		for(long long i=1; i<=qq; i++) {
			cin>>xx>>yy;
			ans=99999999999999999;
			for(long long i=1; i<=n; i++) ans=min(ans,ff[i][xx]+ff[i][yy]);
			printf("%lld\n",ans+wa[xx]+wa[yy]);
		}
	} else {
		for(long long i=1; i<=n; i++) {
			for(long long j=1; j<=m+n; j++) bz[j]=0,d[j]=99999999999999999;
			while(cnt>0) jian();
			d[i+m]=0;
			dij(i+m,i);
		}
		for(long long i=1; i<=qq; i++) {
			cin>>xx>>yy;
			ans=99999999999999999;
			for(long long i=1; i<=n; i++) ans=min(ans,f[i][xx]+f[i][yy]);
			printf("%lld\n",ans+wa[xx]+wa[yy]);
		}
	}
	return 0;
}
