#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
#define int long long
int t,n,d;
int a[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int C;
	cin>>C>>t;
	while(t--)
	{
		int c=0;
		cin>>n>>d;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int js=0;
				for(int k=i+1;k<j;k++)
				{
					if(a[i]+d<a[j]&&a[k]-a[i]<=d&&a[j]-a[k]<=d) 
						js++;
				}
				if(js==2)
					c++;
			}
		}
		cout<<c<<endl;
	}
	return 0;
}
