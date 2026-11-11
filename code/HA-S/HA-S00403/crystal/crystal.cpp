#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=1,min1,max1=-1,s;
struct f{
	long long a1;
	long long a2;
	long long a3;
}a[100005];
bool f1(f x,f y){
	if(x.a1<y.a1){
		return 1;
	}
	return 0;
}
bool f2(f x,f y){
	if(x.a3<y.a3){
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	scanf("%lld",&a[1].a1);
	min1=a[1].a1;                                          		
	for(long long i=2;i<=n;i++){
		scanf("%lld",&a[i].a1);
		a[i].a2=i;
	}
	sort(a+1,a+n+1,f1);
	a[n].a3=0;
	for(long long i=1;i<n;i++){
		a[i].a3=a[i+1].a1-a[i].a1;
	}
	sort(a+1,a+1+n,f2);
	for(long long i=2;i<n;i++){
		s+=a[i].a3;
		if(m-s<0){
			printf("%lld",sum);
			return 0;
		}
		m-=s;
		sum++;
	}
	printf("%lld",sum);
	return 0;
}
