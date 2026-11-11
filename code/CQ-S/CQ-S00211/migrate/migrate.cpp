#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10;
long long a[N];
long long n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long cha=0,f=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			if(i==1)continue;
			if(i==2){
				cha=a[i]-a[i-1];
				continue;
			}
			if(a[i]-a[i-1]!=cha)f=1;
			else cha=a[i]-a[i-1];
		}
		if(!f){
			long long num=d/cha;
			num*=2;
			cout<<max(0LL,n-num+1)<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}
	return 0;
}
