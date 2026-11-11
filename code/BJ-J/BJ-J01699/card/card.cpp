#include <bits/stdc++.h>
using namespace std;
int m,n;
const int N=5e5+10;
int a[N],vis[N],cnt[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    vector<int> tab;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof vis);
        for(int j=i;j<=n;j++)
        {
            if(vis[a[j]]==0)
            {
                tab.push_back(a[j]);
                vis[a[j]]=1;
            }
            else
            {
                int p=tab.size();
                while(1)
                {
                    if(tab[p]==a[j])
                    {
                        break;
                    }
                    else
                    {
                        vis[tab[p]]=0;
                    }
                    p--;
                }
                tab.push_back(j);
                vis[a[i]]=1;
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(vis[j])
            {
                cnt[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}