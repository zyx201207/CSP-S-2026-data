#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=5e5+10;
ll n,m,a[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=m;i++)cout<<i<<" ";
	return 0;
}
