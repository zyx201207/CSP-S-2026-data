#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll maxn=-1,n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	cout<<maxn;
	return 0;
}
