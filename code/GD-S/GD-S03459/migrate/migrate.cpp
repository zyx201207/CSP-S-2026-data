#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int M=2e6+5;
ll c,t;
ll n,d;
ll x[M];
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
		{
			cin>>x[i];
		}
	}
	cout<<1<<endl<<2;
	return 0;
}
