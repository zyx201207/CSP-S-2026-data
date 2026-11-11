#include<bits/stdc++.h>
using namespace std;
const int mxn=2e6+10;
long long x[mxn];
long long n,d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		//int ans;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}		
			if(x[2]-x[1]==x[3]-x[2])
			{
				long long td=d/(x[2]-x[1]);
				//cout<<d<<" "<<x[2]-x[1]<<" ";
				if(td==0||td==1||n<=td)
				{
					cout<<0<<endl;
				}	
				else
				{
					cout<<n-td-1<<endl;
				}
			}
			else
			{
				cout<<0<<endl;
			}

	}
	return 0;
}
