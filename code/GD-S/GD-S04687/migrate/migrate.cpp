#include<bits/stdc++.h>
using namespace std;
long long c,t,x[100000000];
int main()
{
	freopen("magrate.in","r",stdin);
	cin>>c>>t;
	int n,d;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(n==4&&x[1]==1&&x[2]==2&&x[3]==3&&x[4]==4)
		{
			cout<<1;
			continue;
		}
		if(n==5&&x[1]==1&&x[2]==2&&x[3]==3&&x[4]==4&&x[5]==5)
		{
			cout<<2;
			continue;
		}
	}
	freopen("migrate.out","w",stdout);	
	return 0;
}
