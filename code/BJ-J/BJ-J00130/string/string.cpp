#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%s",a+i,c+i);
	long long s=0;
	int l=1,r=n;
	long long lp=1,rp=a[n];
	while(l<r||(l==r&&lp<rp)){
		int d=min(a[l]-lp+1,rp);
		if(c[l]!=c[r])
			s+=d;
		lp+=d;
		rp-=d;
		if(lp>a[l]){
			l++;
			lp=1;
		}
		if(rp<1){
			r--;
			rp=a[r];
		}
	}
	printf("%lld",s);
	return 0;
}
