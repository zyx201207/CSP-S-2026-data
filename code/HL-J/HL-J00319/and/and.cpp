#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,ans=0;
ll a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
    	cin>>a[i];
	}
    sort(a+1,a+n+1);
    ll g=a[n];
	for(ll i=n-1;i>=m;i--){
		ans=g&a[i];
	}		
	cout<<ans;
	return 0;
}