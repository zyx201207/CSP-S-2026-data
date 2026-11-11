#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],f[300005],l;
int st[300005];
int main()
{
	froepen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int j=1;j<=n;j++)
	{
		memset(f,0,sizeof(f));
		l=0;
	    for (int i=j;i<=n;i++)
	    {
	    	if (f[a[i]]==1)
    		{
	    		while(l!=0)
	    		{
	    			
	    			f[st[l]]=0;
	    			l--;
	    			if (st[l]==a[i])
	    			{
	    				l--;
	    				break;
    				}
	    		}
	    	}
	    	st[++l]=a[i];
	    	f[a[i]]=1;
	    }
	    for (int i=1;i<=m;i++)
	    {
	    	cnt[i]+=f[i];
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
}
