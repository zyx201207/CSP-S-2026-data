#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e8+10;
ll a[N],ans=0;
ll n,m;
ll u,v;
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
    	cin>>a[i];
	} 
	n=2*m+1;
	
	cout<<n<<'\n'<<m;
    return 0;
}
