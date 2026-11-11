#include<bits/stdc++.h>
using namespace std;
long long ans=-1,k,x,z,n,m,l,a[200005];
long long pd(long long sx){
	z=sx+m-1;
	k=a[sx];
	for(int i=sx+1;i<=z;i++)
	k=(k&a[i]);
	return k;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    x=n-m+1;
    for(int i=1;i<=n;i++)
    scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
	for(long long i=1;i<=x;i++)
		ans=max(ans,pd(i));
	printf("%lld",ans); 
	return 0;
}
//4 2
//3 15 12 12
//5 3
//31 3 1 15 7

