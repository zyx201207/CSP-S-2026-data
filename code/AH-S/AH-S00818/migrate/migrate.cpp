#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int a[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				int f=0,ind=0;
				for(int k=i+1;k<=j-2;k++)
				{
					if(a[k+2]-a[k]<=d)
					{
//						cout<<i<<" "<<j<<" "<<k<<" "<<j-(k+2)+1<<"\n";
						if(f)
						{
							f=0;
							break;
						}
						ind=k;
						f=1;
					}
				}
				if(f)
				{
					sum+=j-(ind+2)+1;
					break;
				}
			}
		}
		cout<<sum<<"\n"; 
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/


