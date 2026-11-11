#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long x[2000005];
int s;
long long ans;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c<=10) while(t--)
	{
		ans=0;
		map<int,int> a;
		cin >> n >> d;
		for(int i=1;i<=n;i++)
		{
			cin >> x[i];a[x[i]]=1;
		}
			
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int s=0;
				for(int k=1;k<=d;k++)
				{
					for(int y=1;y<=d;y++)
					{
						if(a[x[i]+k]==1&&x[i]+k+y==x[j])
							s++;
					}
				}
				if(s==2)
				{
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
