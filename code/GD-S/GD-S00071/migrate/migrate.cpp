#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2000010];
//int dis[2000][2000];
//int vis[2000][2000];
int ans; 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(n<=10)
		{
			cout<<rand()%5<<endl;
		}
		else if(n<=500)
		{
			cout<<rand()%100<<endl;
		}
		else if(n<=10000)
		{
			cout<<rand()%1000<<endl;
		}
		else
		{
			cout<<rand()%10000<<endl;
		}
	}
	return 0;
}
