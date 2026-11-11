#include<bits/stdc++.h> 
using namespace std;
long long a[500005],st[500005][19],m,n,er[20],lmx,mi,xx,yy;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
for(int i=0;i<=19;i++) er[i]=(1<<i);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int l=1;l<=19;l++){
		mi=m+1;
		if(er[l]>n) break;
		for(int i=1;i+er[l]-1<=n;i++){
			st[i][l]=st[i][l-1]+st[i+er[l-1]][l-1]+er[l-1]*(a[i+er[l]-1]-a[i+er[l-1]-1]);
			if(st[i][l]<mi&&st[i][l]<=m){
				lmx=l;
				mi=st[i][l];
				xx=i;
			} 
		}
	}
	m-=st[xx][lmx];
	lmx=er[lmx];
	yy=xx+lmx;
	while(yy<n){
		if(m-(a[yy]-a[yy-1])*lmx>0){
			m-=(a[yy]-a[yy-1])*lmx;
			yy++;
			lmx++;
		}
		else break;
	}
	printf("%lld",lmx);
	return 0;
}
