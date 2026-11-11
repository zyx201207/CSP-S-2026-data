//GZ-J00311 贵阳市第三中学 杨鑫豪 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005][32],o[32],an[32],k[200005],ans;
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=30;i++)
    {
    	an[i]=0;
	}
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
    {
    	int t=a[i];
    	int x=1;
    	while(t!=0)
    	{
    		b[i][x]=t&1;
    		o[x]+=(t&1);
    		x++;
    		t=t>>1;
		}
	}
	int t;
	for(int i=30;i>=1;i--)
	{
		if(o[i]>=m)
		{
			t=i;
			an[i]=1;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i][t]==1)
		{
			k[i]=1;
		}	
	}
	t--;
	while(t>=1)
	{
		for(int i=1;i<=30;i++)
		{
			o[i]=0;
		}
        for(int i=1;i<=n;i++)
        {
        	if(b[i][t]==1&&k[i]==1)
        	{
        		o[t]++;
			}
			else k[i]=2;
		}
		if(o[t]>=m)
		{
			for(int i=1;i<=n;i++)
      	  	{
        		if(k[i]==2)k[i]=0;
			}
			an[t]=1;
		}
		else 
		{
			for(int i=1;i<=n;i++)
      	  	{
        		if(k[i]==2)k[i]=1;
			}
		}
		t--;
	}
	int res=1;
	for(int i=1;i<=30;i++)
	{
		ans=ans+(an[i]*res);
		res*=2;
	}
    cout<<ans;
    return 0;
}
