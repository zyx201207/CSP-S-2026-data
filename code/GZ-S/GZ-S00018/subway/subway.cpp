//GZ-S00018 µËÔÆÐù
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[5005],a[5005][5005],t[5005][5005];
long long w[500005],x,y,ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
	
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
	    cin >> k[i];
		for(int j=1;j<=k[i];j++)
		{
		    cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--)
	{
		ans=0;
	    cin >> x >> y;
	    ans+=w[x];
	    ans+=w[y];
	    int st[n+1]={},fn[n+1]={};
	    for(int i=1;i<=n;i++)
	    {
	    	for(int j=1;j<=k[i];j++)
	    	{
	    		if(a[i][j]==x)
	    		{
	    			st[i]++;
				}
				if(a[i][j]==y)
				{
					fn[i]++;
				}
			}
		}
		int o=0;
		bool b;
		for(int i=1;i<=n;i++)
		{
			if(st[i]>0&&fn[i]>0)
			{
				o=i;
				b=1;
				break;
			}
		}
		if(b)
		{
	        ans+=t[o][x];
	        ans+=t[o][y];
	    }
	    else
	    {
	        ans+=t[x][x];
	        int u=0,ru=0;
	        for(int i=1;i<n;i++)
	        {
	    	    for(int j=2;j<=n;j++)
	    	    {
	    	    	for(int z=1;z<=k[i];z++)
	    	    	{
	    		    	if(a[i][z]==a[j][z])
	    			    {
	    				    u=i;
	    				    ru=a[i][z];
	    				    break;
					    }
				    }
			    }
		    }
		    ans+=(t[x][ru]+t[u][ru]);
		    ans+=t[u][y];
		}
	    cout << ans << endl;
	}
	return 0;
}
