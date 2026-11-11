#include<bits/stdc++.h>
using namespace std;
int a[200010],maxi,n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int maxi=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==n)
	{
		maxi=a[1];
		for(int i=2;i<=n;i++)
			maxi&=a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		    maxi=max(maxi,a[i]);
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		    for(int j=i+1;j<=n;j++)
		    {
				int c=a[i]&a[j];
				maxi=max(maxi,c);
			}
	}
	if(m==3)
	{
		for(int i=1;i<=n;i++)
    		for(int j=1;j<=n;j++)
        		for(int k=1;k<=n;k++)
        		{
					int c=a[i]&a[j]&a[k];
                    if(i!=j&&j!=k&&i!=k)maxi=max(maxi,c);
				}
	}
	cout<<maxi;
	return 0;
}
