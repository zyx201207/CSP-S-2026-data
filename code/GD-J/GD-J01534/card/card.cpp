#include<bits/stdc++.h>
using namespace std;
long long n,m,sum[500005],a[500005],pos[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
    	memset(pos,-1,sizeof(pos));
    	for(int j=i;j<=n;j++)
    	{
    		if(pos[a[j]]==1) 
			{
				memset(pos,-1,sizeof(pos));
				pos[a[j]]=1;
			}
    		else pos[a[j]]=1;
		}
		for(int j=1;j<=m;j++)
		{
			if(pos[j]==1) sum[j]=sum[j]+1;
		}
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
 } 
 /*
 10 3 
 3 1 2 1 3 2 3 1 2 1*/
