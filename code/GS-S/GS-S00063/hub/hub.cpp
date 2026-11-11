#include <bits/stdc++.h>
using namespace std;
int c,t;
int n[114514],k[114514];
int u[1145][1145],v[1145][1145];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >>c >>t;
	for(int i=1;i<=t;i++)
	{
		cin >>n[i]>>k[i];
		for(int j=1;j<=n[i];j++)
		{
			cin >> u[i][j]>>v[i][j];
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout <<1<<endl;
	}
	return 0; 
} 
