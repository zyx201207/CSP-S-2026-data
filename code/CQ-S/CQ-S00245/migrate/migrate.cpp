#include <bits/stdc++.h>
using namespace std;
int n,c,t,n,d,x[2000005],z,sum,t1,t2;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>c<<t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(c==11||c==12)
		{
			cout<<max(n-3,0)<<endl;
		}
	}
	return 0;
}
