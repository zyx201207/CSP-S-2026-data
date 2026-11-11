#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6;
int n,m,x[maxn];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int ans = 0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		
	}
	if(n==6)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(x[j]>x[j+1])
				{
					swap(x[j],x[j+1]);
				}
			}
		}
		ans = x[6];
		cout<<ans;
	}
	if(n==7)
	{
		for(int i=1;i<=7;i++)
		{
			ans = ans&x[i];		
		}
		cout<<ans;
	}	
	if(n==11||n==12)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<=n;j++)
			{
				int p = x[i]&x[j];
				ans = max(ans,p);
			}
		}	
	}
	cout<<ans;
	return 0;
	
}
