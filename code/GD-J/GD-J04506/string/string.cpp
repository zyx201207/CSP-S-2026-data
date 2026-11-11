#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[1000000],b[1000000],c[1000000],d[1000000],ans=0,sum=0,cum=0,i;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		for(int i=ans;i<ans+x;i++)
			a[i]=y;
		ans+=x;
	}
	int t,w;
	if(ans%2==1)
	{
		for(int i=0;i<ans/2-1;i++)
			b[i]=a[i];
		for(int i=ans/2+1;i<ans;i++)
			t=a[i];
			w=ans/2+1;
			c[i-w]=t;
			
		for(int i=0;i<ans/2-1;i++)
		{
			if(b[i]!=c[i])
				sum+=1;
		}
		cout<<sum;				
	}
	else
	{
		for(int i=0;i<ans/2-1;i++)
			b[i]=a[i];
		for(int i=ans/2;i<ans;i++)
			t=a[i];			
			c[i-ans/2]=t;			
		for(int i=0;i<ans/2;i++)
		{
			if(b[i]!=c[i])
				sum+=1;
		}
		cout<<cum;				
	}
	return 0;
}

