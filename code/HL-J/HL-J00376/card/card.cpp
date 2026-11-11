#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int c[N],cnt=0;
	for(int i=1;i<=n;i++)
	{		
		bool flag=0;
		c[i]=a[i];
		if(a[i]==i&&!flag)
		{
			c[i]=a[i];
			flag=1;
		}
		else
		{
			bool f=0;
			for(int j=1;i<=n;j++)
			{				
				if(c[j]==i||f)
				{
					f=1;
					c[j]=0;
				}
			} 
			flag=1;
		}
		for(int j=1;j<=n;j++)
		{
			if(c[j]==i)
			{
				cnt++;
			}
		}
		cout<<cnt<<' ';
	}
	return 0;
}
