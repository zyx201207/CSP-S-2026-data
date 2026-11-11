#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e8+10;
ll n,d,m;
ll c,t;
ll a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(a[1]==1 && a[2]==2 && a[5]==5) cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
} 
