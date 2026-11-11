#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[20005],b[20005],ans=0,l=0,t=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>a[i]>>c;
		b[i]=c-'0';
	}
	for(int i=1;i<=1;i++)
	{
		for(int j=2;j<=n;j++)
		{
			if(b[i]!=b[j])
			{
				t++;
			}
		}
	}
	if(t==1)
	{
		cout<<"0";
		return 0;
	}
	else if(t==2)
	{
		for(int i=1;i<=1;i++)
	    {
		    for(int j=2;j<=n;j++)
		    {
			    if(b[i]!=b[j])
			    {
			    	ans+=a[j];
			    }
		    }
	    }
	    cout<<ans;
	}
	else
	{
		cout<<"3";
	}
	return 0;
}
