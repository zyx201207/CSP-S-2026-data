#include <bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n,m,a[MAXN],f[MAXN]; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	int ans=0,c=0,d=0;
	for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
        {
    	    if(i!=j&&a[i]&a[j]>ans)
    	    {
    	    	ans=a[i]&a[j];
    	    	c=i;
    	    	d=j;
			}
    	}
	}
	f[c]=1;
	f[d]=1;
	m-=2;
	int cnt=ans;
	while(m--)
	{
		int g=0;
		for(int i=1;i<=n;i++)
        {
    	    if(f[i]==0&&a[i]&cnt>ans)
    	    {
    	       ans=cnt&a[i];
    	       g=i;
			}
    	}
    	f[g]=1;
    	cnt=ans;
	}
	cout<<ans;
	return 0;
} 
