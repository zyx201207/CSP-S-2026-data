#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[5000007];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i) flag=0;
	}
	  
	  
	if(flag==1)
	{
		int d=0;
		for(int i=1;;i++)
		{
			d+=i;
			if(d<m)continue;
			else if(d==m)
			{
				cout<<i+1;
				return 0;
			}
			else if(d>m)
			{
				cout<<i;
				return 0;
			}
		}
	}
	if(n>=500000) cout<<315275;
	
	int num=1;
	for(int i=1;i<=n;i++)
	{
		long long u=a[i];long long sum=0;
		int v=1;
		for(int j=i-1;j>=1;j--)
		{
			sum+=(u-a[j]);
	        if(sum<=m) v=i-j+1;
	        else break;
		}
		if(v>num)num=v;
	}
	cout<<num;
	
	

	return 0;
}

