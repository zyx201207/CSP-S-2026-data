#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int p1[200005];
int p2[200005];
long long f(long long x,int y){
	return (x>>(y-1))&1;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	for(int i=1;i<=n;i++)
		p1[i]=1;
	int *p=p1,*d=p2;
	long long s=0;
	for(int i=30;i>=1;i--){
		int k=0;
		for(int j=1;j<=n;j++)
			k+=(d[j]=((p[j])&f(a[j],i)));
		if(k>=m){
			s+=(1<<(i-1));
			swap(p,d);
		}
	}
	printf("%lld",s);
	return 0;
}
