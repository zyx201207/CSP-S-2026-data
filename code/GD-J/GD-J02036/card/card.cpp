#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5*1e5+10;
ll n,m;
ll a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=m;i++){
		cout<<a[0]<<" ";
	}
	return 0;
}
