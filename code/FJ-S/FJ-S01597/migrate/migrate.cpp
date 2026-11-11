#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[200006]={0};
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
	}
	cout<<n/2;
	return 0;
}
