#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e8+10;
ll a[N],ans=0; 
ll n,m;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
    	cin>>a[i];
		ll x,y,d;
		cin>>x>>y>>d;
		if(x-y>=10*d){
			n=n+1;
		}
	} 
	cout<<n<<'\n'<<m;
    return 0;
}
