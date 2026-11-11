#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if(c==0||c==12){
		while(t--){
			//cout <<"sda"<<'\n';
			long long n,d;
			cin >> n >> d;
			long long x=0,x0;
			for(int i=1;i<=n;i++){
				x0=x;
				cin >> x;
				
			}
			//cout <<"set"<<n <<' '<<d<<' '<<x0<<' '<<x<<'\n';
			long long l=d/(x-x0);
			long long ans=0;
			for(long long i=2;i<=l;i++){
				if(n-l*2+1<0)break;
				ans+=n-l*2+1;
			}
			cout << ans<<'\n';
		}
	}

	return 0;
}

