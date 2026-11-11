#include<bits/stdc++.h>
using namespace std;
int n;
long long d,x[100005],dis[100005][100005];
int c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			if(x[i]-x[i-1]<=d) dis[i-1][i]=dis[i][i-1]=1;
		}
	}
	return 0;
}
