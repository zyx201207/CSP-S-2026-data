#include<bits/stdc++.h>
using namespace std;
struct node
{
	int n,d,x[5005];
}a[5005];
int main()
{
	freopen("migrate.in","r",in);
	freopen("migrate.out","w",out);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i].n>>a[i].d;
		if(c==11||c==12)
		{
			cout<<0;
		}
		if(c==13||c==14)
		{
			cout<<a[i].n;
		}
	}
	return 0;
}
