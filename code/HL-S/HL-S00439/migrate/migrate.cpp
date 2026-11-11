#include<bits/stdc++.h>
#include<cmath>
using namespace std;
const int N=2e6+10;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int j=1;j<=t;j++)
	{
		int n,d,rd;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c==11||c==12)
		{
			rd=a[2]-a[1];
			int sum=d/rd;
			if(sum<2)
			{
				cout<<0<<"\n";
				continue;
			}
			else
			{
				if(n>=2*sum)
				{
					cout<<n-2*sum+1<<"\n";
					continue;
				}
				cout<<0<<"\n";
			}
		}
		else
		{
			cout<<0<<"\n";
		}
	}
	return 0;
}