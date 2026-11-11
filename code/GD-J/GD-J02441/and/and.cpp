#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll n,m,ans,pq;
ll a[N],p[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n-m;i++){
		for(ll j=i;j<=i+m;j++){
			pq=a[j]&a[j-1];
		}
		ans=max(ans,pq);
	} 
	cout<<ans;
	return 0;
}
