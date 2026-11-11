#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,x[2000005],ans=0;
bool check(int a,int b,int c)
{
	if(a<0&&b<0)
	{
		a*=-1,b*=-1;
		if(a-b==c) return true;
		else
		{
			return false;
		}
	}
	else if(a<0&&b>0)
	{
		a*=-1;
		if(a+b==c)return true;
		else
		{
			return false;
		}
	}
	else
	{
	    if(b-a==c) return true;
	    else 
	    {
	    	return false;
	    }
    }
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		if(d==1) break;
		long long cnt=2*d-1,ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				if(check(x[i],x[j],cnt))
				{
					ans++;
				}
			}
		} 
		cout<<ans<<endl;
	}
	return 0;
}
