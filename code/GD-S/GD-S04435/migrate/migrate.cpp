#include<iostream>
#include<cstdio>
using namespace std;
long long c,t;
long long n,d,a[200005],ans;
long long sh(long long q,long long z)
{
	cout<<q<<z;
	long long qwert=q,qwerty=z;
    if(z-q==1)return 1;
	long long daanaa=0;
	if(a[z]-a[q]<=d)daanaa++;
	for(long long p=q+1;a[p]-a[q]<=d;p++)daanaa=daanaa+sh(qwert,p)+sh(p,qwerty)-1;
	return daanaa;
}
int main()
{
	cin>>c>>t;
	
	if(c<=10||c==19||c==20||c==21)
	{
		for(long long qwe=1;qwe<=t;qwe++)
		{
			cin>>n>>d;
    		for(long long i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			for(long long i=1;i<=n-2;i++)
			{
				for(long long j=i+2;j<=n;j++)
				{
					if(sh(i,j)==2)ans++;
				}
			}
			cout<<ans<<endl;
    	}
	}
	if(c==11||c==12)
	{
		for(long long i=1;i<=t;i++)
		{
			long long a,b,x;
			cin>>n>>d;
			cin>>a>>b;
			for(long long j=3;j<=n;j++)cin>>x;
			long long cha=b-a;
    		if(2*d/cha>=n)
    		{
    			cout<<n+1-2*d/cha<<endl;
			}
			else cout<<0<<endl;
		}
	}
	return 0;
}
