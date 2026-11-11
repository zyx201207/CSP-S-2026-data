#include<iostream>
using namespace std;
int c,t;
inline long long read()
{
	long long f=1,x=0;
	char c;
	c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
			f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void solve()
{
	int n;
	long long d,ans=0;
	cin>>n>>d;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	 } 
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]+d+1==a[j])
				ans++;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	c=read(),t=read();
	for(int i=1;i<=t;i++)
		solve();
}
