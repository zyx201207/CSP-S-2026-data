#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

long long c,t,n,d,a[2000005],ans; 

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c>>t;
	while(t--){
		cin >>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		long long y=a[2]-a[1],x=d/y;
		if(x==1||x==0||x<0)cout << 0<<'\n';
		else {
			x=x*2;
			long long k=0;
			cout << max(n-x+1,k) <<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
