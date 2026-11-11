#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e8+10;
ll a[N],ans=0;
ll n,m;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
    	cin>>a[i];
		if(m--){
		ans++;
		}
	} 
	cout<<ans-2;
    return 0;
}












