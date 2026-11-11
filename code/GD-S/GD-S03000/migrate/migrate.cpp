#include<bits/stdc++.h>
using namespace std;
int c,t,n,a[2000005];
long long d,ans;
int main()
{
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++)
				scanf("%d",&a[i]);
			if(a[3]-a[1]<=d)
			{
				ans+=n-2;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	else if(c==13||c==14)
	{
		while(t--)
		{
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++)
				scanf("%d",&a[i]);
			
		}
	}
	return 0;
}
