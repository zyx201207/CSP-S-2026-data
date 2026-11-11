#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,sum=0;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	cout<<sum/n;
	return 0;
}
