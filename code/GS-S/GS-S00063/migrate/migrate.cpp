#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long place[229028];
int ans[114514];
int temp;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int p=1;p<=t;p++)
	{
		cin >>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin >>place[i];
		}
		if(n<=3)
		{
			ans[p]=0;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(place[i]+d<place[i+1])
			{
				continue;
			}
			else
			{
				for(int j=i+3;j<=n;j++)
				{
					if(place[i]+place[i+1]<d&&place[j]+place[j-1]<d)
					{
						ans[p]++;
					}
					
				}
			}
		}
		
		n=0;
		d=0;
	}
	for(int i=1;i<=t;i++)
	{
		cout <<ans[i]<<endl;
	}
	return 0;
}
