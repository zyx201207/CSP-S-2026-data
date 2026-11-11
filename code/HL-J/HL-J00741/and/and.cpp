#include<bits/stdc++.h>
using namespace std;
int a[35];
int b[200005][35];
int jin[35],d[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0,x;
	cin>>n>>m;
	jin[1]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		int cnt=1;
		while(x!=0)
		{
			if(x%2==1)
			{
				a[cnt]++;
				b[i][cnt]=1;
			}
			cnt++;
			x/=2;
		}
		if(i!=1)
		{
			jin[i]=jin[i-1]*2;
		}
	}
	int f=0;
	for(int i=30;i>=1;i--)
	{
		if(a[i]>=m)
		{
			f=i;
			break;
		}
	}
	if(f==0)
	{
		cout<<0;
	}
	else
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i][f]==1)
			{
				cnt++;
				d[cnt]=i;
			}
		}
		if(cnt==m)
		{
			int biao=1;
			for(int i=1;i<=cnt;i++)
	    	{
		     	if(b[d[i]][f]==0)
		    	{
	    		    biao=0;
	     		}
	     	}
	     	if(biao==1)
	     	{
	     	    ans+=jin[f];
			}
		}
		while(cnt>m&&f>=1)
		{
			int tmp=0;
			for(int i=1;i<=cnt;i++)
			{
				if(b[d[i]][f]!=1&&d[i]!=-1)
				{
					tmp++;
				}
			}
			if(cnt-tmp>=m)
			{
				int biao=1;
				for(int i=1;i<=cnt;i++)
		    	{
		     		if(b[d[i]][f]==0)
		    		{
	    			    d[i]=-1;
	    			    biao=0;
	     			}
	     		}
	     		if(biao==1)
	     		{
	     			ans+=jin[f];
				 }
	     		
			}
			else
			{
				if(tmp==0)
				{
					ans+=jin[f];
				}
			}
			f--;
		}
	}
	cout<<ans;
	return 0;
}