#include<bits/stdc++.h>
using namespace std;

int const N=1e6+10;
long long a[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	long long cnt=0;
	scanf("%ldd",&c);
	scanf("%lld",&t);
	while(t--){
		long long n,d;
		scanf("%lld",&n);
		scanf("%lld",&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		bool f=false;
		for(int i=n;i>=1;i--){
			for(int j=n-1;j>=1;j++){
				if(a[i]-a[j]==d&&!f){
					f=true;
					cnt++;
				}
			}
		}
		printf("%lld ",cnt);
	}
	
	return 0;
}
