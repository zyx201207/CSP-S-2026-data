#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main()
{
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	int n,m,cnt=0,s=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	    
	}
	int j=1,c=1;
	for(int i=2;i<=n;i++)
	{
		if(j>=1)
		{
			while(j--)
			{
				s=s+a[j];
				c++;
			}
			cnt=a[i]*j-s;
	    }
	    j++;
	    if(cnt==m)
	    {
		  	cout<<i;
	   	}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
