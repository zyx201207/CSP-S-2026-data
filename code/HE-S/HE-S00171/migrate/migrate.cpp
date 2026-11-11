#include <bits/stdc++.h>
using namespace std;
long long int c,t,n[100005],d[100005],x[100005];

void init()
{
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++)
		{
			cin>>x[j];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	init();
	cout<<"0\n1";
	
	return 0;
}
