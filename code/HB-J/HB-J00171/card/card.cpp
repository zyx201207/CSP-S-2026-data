#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
const int N=6005;
bool vis[N],vis1[1005];
int a[N],zhuo[1005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof vis);
        memset(vis1,0,sizeof vis);
        memset(zhuo,0,sizeof zhuo);
        int r=0;
        for(int j=i;j<=n;j++)
        {
            if(vis[a[j]]==0)
            {
                zhuo[++r]=a[j];
                vis[a[j]]=1;
            }
            else
            {
                int t=0;
                bool flag=false;
                for(int k=1;k<=r;k++)
                {
                    if(zhuo[k]==a[k])
                    {
                        t=k-1;
                        flag=true;
                    }
                    if(flag) vis[a[k]]=0;
                }
                r=t;
                zhuo[++r]=a[j];
                vis[a[j]]=1;
            }
        }
        for(int j=1;j<=r;j++)
        {
            if(!vis1[zhuo[j]])
            {
                mp[zhuo[j]]++;
                vis1[zhuo[j]]=1;
            }

        }
    }
    for(int i=1;i<=m;i++) cout<<mp[i]<<" ";
    return 0;
}
