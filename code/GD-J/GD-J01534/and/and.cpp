#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx=-1,g=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==n)
    {
    	long long k=a[1];
    	for(int i=1;i<=n;i++) k=k&a[i];
        cout<<k;
    	return 0;
	}
    if(m==1)
	{
		cout<<maxx;
		return 0;
	} 
    if(m==2)
    {
    	for(int i=1;i<=n;i++)
    	{
    		int s=a[i];
    		for(int j=i;j<=n;j++)
    		{
    			if(j==i) continue;
    			g=max(g,s&a[j]);
			}
		}
		cout<<g;
		return 0;
	}
	if(m==n-1)
	{
		int maxy=-41;
		for(int i=1;i<=n;i++) 
		{
			int h=a[i];
			for(int j=1;j<=n;j++)
			{
			    if(j==i) continue;
			    else h=h&a[j];
			}
			maxy=max(maxy,h);
		}
		cout<<maxy;
		return 0;
	}
	return 0;
 } 
