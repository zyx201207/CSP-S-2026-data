#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		vector<ll> x(n+1);
		for(int i=1;i<=n;i++) cin>>x[i];
		
		ll cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d) continue;
				if((x[j]-x[i])*1.0/d>1 && (x[j]-x[i])*1.0/d<2)
					cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
