#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],cnt[300005],t,i;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(m==1)cout<<n;
	return 0;
}
