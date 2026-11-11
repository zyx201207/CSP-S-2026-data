#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const ll N=2e6+10,M=5e3+10,MAX=1e9;
ll n,m,a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		ll ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	sort(a+1,a+n+1);
	//cout<<a[n-m+1];
	ll ans=a[n-m+1];
	cout<<ans;
	return 0;
} 
