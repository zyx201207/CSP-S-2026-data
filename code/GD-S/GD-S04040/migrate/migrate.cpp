#include<bits/stdc++.h>
using namespace std;
int c,T;
long long n,d,ans;
long long s[500005],l[500005];
long long v[500005],t[500005];
void Work(int x)
{
	v[x]=0;
	t[x]=1;
	for(int i=x+1;i<=n;i++)
		v[i]=2e18,t[i]=1;
	for(int i=x;i<=n;i++)
	{
		for(int j=i+1;j<=l[i];j++)
		{
			if(v[i]+1==v[j])
				t[j]+=t[i];
			else if(v[i]+1<v[j])
				v[j]=v[i]+1,t[j]=t[i];
		}
	}
	for(int i=x;i<=n;i++)
	{
		if(t[i]==2) ans++;
	}
}
void Work2()
{
	long long y=s[2]-s[1],z=0;
	z=d/y;
	z=z*2-1;
	printf("%lld\n",n-z);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		scanf(" %lld %lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf(" %lld",&s[i]);
		if(n>5000){
			Work2();
			continue;
		}
		
		l[0]=1;
		for(int i=1,ii=0;i<=n;i++)
		{
			ii=l[i-1];
			while(s[i]+d>=s[ii]&&ii<=n) ii++;
			ii--;
			l[i]=ii;
		}
		for(int i=1;i<=n;i++)
			Work(i);
		printf("%lld\n",ans);
	}
	return 0;
 } 
