#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6,inf=1e18;
ll n,m;
ll v[N],a[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<n<<" ";
	}
	return 0;
}