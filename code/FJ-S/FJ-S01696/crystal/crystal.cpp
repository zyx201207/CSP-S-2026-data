#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,t,ans=0,p;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
	    cin>>a[i];
    }
    for(int i=a[n];i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			int x=a[j]-i;
			if(a[j]>=i)p=p+x;
		}
		
		//cout<<i<<endl;
		//cout<<p<<endl;
		//cout<<"__________"<<endl;
		if(p<=m)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j]<=i)
				{
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
