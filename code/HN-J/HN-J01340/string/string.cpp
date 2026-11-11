#include<bits/stdc++.h> 
using namespace std;
int n,stater,last;
long long sum[200010],ans=0;
struct aaa
{   
    int gs;
	char zm;
	
}c[200010];
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
  cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>c[i].gs>>c[i].zm;
	sum[i]=sum[i-1]+c[i].gs;
}
for(int i=1;i<=n;i++)
{
	if(sum[i]*2==sum[n])
	{   last=i;
		stater=i+1;
		break;
	}
	if(sum[i]*2>sum[n])
	{
		last=i;
		stater=i+1;
		n++;
		for(int j=n;j>=stater;j--)
		{
		c[j].zm=c[j-1].zm;
		c[j].gs=c[j-1].gs;	
		}
		int x=((sum[i]*2-sum[n-1])-(sum[i]*2-sum[n-1])%2)/2;
		c[i].gs=c[i].gs-x;
		c[i+1].gs=x;
		break;
	}
}
int i=1,j=n; 
 
while(i<=last||j>=stater)
{
	if(int(c[i].zm)==int(c[j].zm))
	{
		if(c[i].gs>=c[j].gs)
	{
		c[i].gs-=c[j].gs;
		c[j].gs=0;
	}
	else
	{
		c[j].gs-=c[i].gs;
		c[i].gs=0;
	}
	}
	else
	{if(c[i].gs>=c[j].gs)
	{
		c[i].gs-=c[j].gs;
		ans+=c[j].gs;
		c[j].gs=0;
	}
	else
	{
		c[j].gs-=c[i].gs;
		ans+=c[i].gs;
		c[i].gs=0;
	}
	
	}
	
	if(c[i].gs==0)
	i++;
	if(c[j].gs==0)
	j--;
}
cout<<ans;
	return 0;
}
