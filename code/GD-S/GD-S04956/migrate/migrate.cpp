#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	int y[t+2]={0};
	for(int i=0;i<t;i++)
	{
		cin>>n>>d;
		for(int j=0;j<n;j++)
		{
			int x[n+2];
			cin>>x[j];
			for(int k=0;k<n;k++)
			{
				if(x[j]==x[k+d]-d)
				{
					if(x[j]+d==x[k+d])
					{
						y[i]+=1;
					}
				}
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		cout<<y[i]<<endl;
	}
	return 0;
}
