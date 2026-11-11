#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],last[300001],ans[300001];
bool vis[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=300000;j++)
        {
            vis[j]=0;
            last[j]=0;
        }
        for(int j=i+1;j<=n;j++)
        {
            if(vis[a[j]])
            {
                for(int k=1;k<=m;k++)
                {
                    if(last[k]>last[a[j]])
                    {
                        last[k]=0;
                        vis[k]=0;
                    }
                }
            }
            last[a[j]]=j;
            vis[a[j]]=1;
        }
        for(int j=1;j<=m;j++)
        {
            if(vis[j])
            {
                ans[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
	return 0;
}
