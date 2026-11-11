#include <bits/stdc++.h> 
using namespace std;
long long c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		long long n,d,x[2*100000+10],ans=0,len=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			if(i>1)
			{
				if(x[i]-x[i-1]==1)len++;
				else 
				{
					if(len>=d*2)ans+=(len-d*2+1);
					len=1;
				}
			}
		}
		if(len>=d*2)ans+=(len-d*2+1);
		if(d==1)
		{
			cout<<0<<endl;
			continue;
		}
		cout<<ans<<endl;
	}
	return 0;
}
