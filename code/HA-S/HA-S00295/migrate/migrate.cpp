#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	

	ll c,t;
	cin>>c>>t;
	ll n,d;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		if(n<4){
			cout<<0<<"\n";
			break;
		}
		vector<ll>ve(n);
		for(int j=0;j<n;j++){
			cin>>ve[j];
		}
		ll l=0,r = 3;
		ll sum_ = 0;
		while(r<=n-1 && l<=n-1){
		
			if(ve[r]-ve[l]>d && ve[r]-ve[l] < 2*d && ve[r-2]+d >= ve[r] && ve[r-3]+d < ve[r]){
				sum_++;
			}
			r++;
			l++;
			
			
			
			
			
		}
		cout<<sum_<<'\n';
		
		
	}
	return 0;
}
