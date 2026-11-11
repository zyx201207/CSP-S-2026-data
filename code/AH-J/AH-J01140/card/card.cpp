#include<bits/stdc++.h> 
using namespace std;
long long s[300005],f[300005],a[500005],y[300005];
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		y[a[i]]++;
		if(a[i]<a[i-1])
		  x=0;
	}
	if(x==1)
	{
		for(int i=1;i<=m;i++)
		{
			y[i]+=y[i-1];
			cout<<y[i]<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(s[a[j]]==0)
		    {
			    s[a[j]]=j-i+1;
	      	}
		    else
		    {
			    for(int k=1;k<=m;k++)
			    {
				    if(s[k]>s[a[j]]&&s[k]<j-i+1)
				    {
					    s[k]=0;
				    }
			    }
			    s[a[j]]=j-i+1;
		    }
		}
		for(int j=1;j<=m;j++)
		{
			if(s[j]>0)
			  f[j]++;
			s[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<f[i]<<endl;
	}
	return 0;
}
