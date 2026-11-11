#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+1;
ll c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ll n,d,x[N];
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(n%2==0)
		{
			cout<<x[1]<<endl;
		}
		else{
			cout<<x[2]<<endl;
		}
	}
	return 0;
}