#include<bits/stdc++.h>
using namespace std;
int a[500010];
int box[210];
bool vis[500010],viss[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            for(int k=n;k>j;k--)
            {
                if(a[j]==a[k])
                {
                    for(int z=j;z<k;z++)
                    {
                        vis[z]=true;
                    }
                }
            }
        }
        for(int j=i;j<=n;j++)
        {
            if(!vis[j]&&!viss[a[j]])
            {
                box[a[j]]++;
                viss[j]=true;
            }
        }
        for(int i=1;i<=5010;i++)
        {
            vis[i]=viss[i]=false;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(i==a[n])
            cout<<n<<" ";
        else
            cout<<box[i]<<" ";
    }
}