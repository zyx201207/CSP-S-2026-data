#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof(x));
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		long long l=x[2]-x[1];
		long long p=(d/l);
		long long ans=(n-2*p+1);
		if(ans<0||p<=1) ans=0;
		cout<<ans<<endl;
	}
	
	return 0;
}
