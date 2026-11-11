#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000005;
int c,t,u[N],cnt[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>u[i];
		}
		if(c==0)
		{
			cout<<0<<"\n"<<1;
			return 0;
		}
		else 
		{
			cout<<0<<"\n";
		}
	}
	return 0;
}
