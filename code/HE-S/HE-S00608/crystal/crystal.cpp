#include<bits/stdc++.h>
using namespace std;

int const N=1e5+5;
long long a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	long long cnt=0,sum=0,x=m,cs;
	for(long long i=2;i<=n;i++){
		cs=a[i];
		long long x=m;
		for(long long j=i-1;j>=1;j--){
			if(a[i]-a[j]<=x){
				x-=a[i]-a[j];
				a[j]+=a[i]-a[j];
			}
		}
		if(x==0){
			break;
		}
	}
	for(long long i=1;i<=n;i++){
		if(cs==a[i]){
			cnt++;
		}
	}
	printf("%lld",cnt);
	
	return 0;
}
