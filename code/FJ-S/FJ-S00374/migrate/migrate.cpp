#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		vector<int> x(n);
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
		}
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				bool ok=1;
				for(int k=i;k<j;k++)
				{
					if(x[k+1]-x[k]>d)
					{
						ok=0;
						break;
					}
				}
				if(ok)
				{
					cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
}
