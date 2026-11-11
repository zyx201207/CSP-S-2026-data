#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		long long n,d;
		cin>>n>>d;
		long long a[2000005]={};
		for(long long i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(c==11||c==12){
			long long x=abs(a[2]-a[1]);
			if(d<=x) cout<<0<<endl;
			else{
				cout<<n-(n-1)/(d/x)-d/x<<endl;
			}
			
		}
	}
}
