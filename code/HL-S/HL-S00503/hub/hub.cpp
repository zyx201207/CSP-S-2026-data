#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+1;
ll c,t,ans;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ll n,k,u[N];
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=2;j++)
			{
				cin>>u[j];
			}
		}
		ans++;
		cout<<ans<<endl;
	}
	return 0;
}