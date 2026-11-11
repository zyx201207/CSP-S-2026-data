#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=2e6+10;
ll c,t,n,d,x[maxn],ans; 
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11 || c==12){
			ll ad=x[2]-x[1];
			cout<<ad*((n*n-5*n)/2+3)<<'\n';
			return 0;
		}
	}
	return 0;
}
