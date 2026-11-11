#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50010],b[50010],maxn=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
		for(long long j=1;j<i;j++){
			long long x=b[i]-b[j-1];
			if(a[i]*(i-j+1)-x<=m)maxn=max(maxn,i-j+1);
		}
	}
	printf("%d",maxn);
	return 0;
}
