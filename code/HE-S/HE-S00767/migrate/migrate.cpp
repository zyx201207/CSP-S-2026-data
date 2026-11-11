#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int c,t;
int x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		int ans=n-d*2;
		cout<<ans+1<<"\n";
	}
	return 0;
}

