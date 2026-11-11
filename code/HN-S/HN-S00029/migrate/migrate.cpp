#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(int i=t;i>0;i--)
	{
		long long n,d,a[10000];
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i];
		}
		if(n%d==0)
		{
			cout<<"1"<<endl;
		}
		else
		{
			cout<<"2"<<endl;
		}
	}
	return 0;
} 
