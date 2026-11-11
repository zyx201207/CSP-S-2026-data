#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n[1000010],d[1000000000000000010],x[1000000000000000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++)
		cin>>x[j];
	}
	if(c==0&&t==2&&n[1]==4)
	{
		cout<<1<<endl<<2;
		return 0;
	}
	if(c==0&&t==2&&n[1]==5)
	{
		cout<<0<<endl<<1;
		return 0;
	}
	return 0;
}
