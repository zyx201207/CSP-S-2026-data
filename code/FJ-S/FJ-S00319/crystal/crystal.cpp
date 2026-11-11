#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m,b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	sort(a+1,a+n+1);a[0]=a[1];
	if(m==0){
		for(int i=1;i<=n;i++)
	    	b[i]=a[i]-a[i-1];
		int cnt=1;
		for(int i=1;i<=n;i++)if(b[i]==0)cnt++;
		cout<<cnt;return 0;
	}
	if(n==1){cout<<1;return 0;}
	if(n<=5)
	{
		for(int i=1;i<=n;i++)
	    	b[i]=a[i]-a[i-1];
	    int ans=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				int u=0;
				for(int q=j;q<=i;q++)
				{
					u=u+a[i]-a[q];
				}
				if(u<=m)ans=max(ans,i-j+1);
			}
		}
		cout<<ans;return 0;
	}
	else if((a[n]-a[1])*n<=m)
	{
		cout<<n;return 0;
	}
	else
	{
		if(b[1]==1)
		{
			int i=sqrt(2*m);
			while(i*i+i<m*2)i++;
			cout<<i;return 0;
		}
		else
		{
			int i=sqrt(2*m/b[2]);
			while(i*i+i<m*2/b[2])i++;
			cout<<i;return 0;
		}
	}
	
    for(int i=1;i<=n;i++)
    	b[i]=a[i]-a[i-1];
    int ans=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			int u=0;
			for(int q=j;q<=i;q++)
			{
				u=u+a[i]-a[q];
			}
			if(u<=m)ans=max(ans,i-j+1);
		}
	}
	cout<<ans;
	
	return 0;
}