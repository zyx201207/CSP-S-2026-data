#include<bits/stdc++.h>
using namespace std;
int n,c,t,d;
int x[1000000];
int main()
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
			cin>>x[i];
		}
		for(int i=4;i<=n;i++)
		{
			if((x[i-2]-x[i-3]<=d)&&(x[i-1]-x[i-3]<=d)){
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}
