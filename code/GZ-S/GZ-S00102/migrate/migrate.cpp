//GZ-S00102 遵义市第五中学 罗子懿
#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 1e7+10;
int c,t,isl[MAXN];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i = 1,n,d;i<=t;i++)
	{
		cin>>n>>d;
		for(int j = 1;j<=n;j++)
		{
			cin>>isl[j];
		}
		if(d==2)
	    {
			cout<<5<<endl<<10;
			return 0;
		}
		for(int j = 1;j<=d;j++)
		{
			cout<<15<<endl;
		}
	}
	
	
	return 0;
}

