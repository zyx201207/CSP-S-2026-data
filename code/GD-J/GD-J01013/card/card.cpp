#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005]; 
bool vis[300005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
    	int w=i;
    	for(int j=i;j<=n;j++)
    	{
    		if(vis[a[j]])
    		{
    			for(int c=i;c<j;c++) vis[a[c]]=0;
    			w=j;
			}
			vis[a[j]]=1;
		}
		for(int j=w;j<=n;j++) s[a[j]]++;
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
    return 0;
}
// no:1= ? AFO
//jin li le
//www
//lguid:1151818
