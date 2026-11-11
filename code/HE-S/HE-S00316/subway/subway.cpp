#include<bits/stdc++.h>
using namespace std;
int c,n,m,nn,q,w[100005],d[20005],t[20005],k;
int l[20005][20005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>c>>n>>m>>nn>>q;
    for(int i =1;i<=m;i++)
    {
    	cin>>w[i];
	}
	for(int i = 1;i<=n;i++)
	{
		cin>>k;
		for(int j = 1;j<=k;j++)
		{
			cin>>d[j]>>t[j];
		}
		for(int x = 1;x<=k;x++)
		{
			for(int y = x+1;y<=k;y++)
			{
				if(l[d[x]][d[y]]==0){
					l[d[x]][d[y]]=t[x]+t[y];
				}
				else l[d[x]][d[y]]=max(l[d[x]][d[y]],t[x]+t[y]);
				if(l[d[y]][d[x]]==0)l[d[y]][d[x]]=t[x]+t[y];
				else l[d[y]][d[x]]=max(l[d[y]][d[x]],t[x]+t[y]);
			}
		}
	}
	for(int i = 1;i<=m;i++)
    {
    	for(int j = 1;j<=m;j++)
    	{
    		for(int a = 1;a<=m;a++)
	    	{
	    		if(l[i][a]!=0&&l[a][j]!=0&&(l[i][a]+l[a][j]<l[i][j]||l[i][j]==0)){
	   			    l[i][j]=l[i][a]+l[a][j];
				}
	    	}
	    }
	}
	int xx,yy;
	for(int i = 1;i<=q;i++)
	{
		cin>>xx>>yy;
		if(l[xx][yy]!=0)cout<<l[xx][yy]+w[xx]+w[yy]<<"\n";
		else cout<<0<<"\n";
	}
	return 0;
}
