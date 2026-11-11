#include<bits/stdc++.h>
using namespace std;
int ans[3010];
int lst=1;
int lt[3010];
bool vis[3010];
int main()
{
//    freopen("card.in","r",stdin);
//    freopen("card.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int a[5010];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(lt,0,sizeof(lt));lst=i;
        memset(vis,1,sizeof(vis));
        for(int j=i;j<=n;j++)
        {
            if(lt[a[j]]>0&&lt[a[j]]>=lst)
            {
                lst=lt[a[j]];
            }
            lt[a[j]]=j;
        }
        for(int j=lst;j<=n;j++)
        {
            ans[a[j]]+=vis[a[j]];
            vis[a[j]]=0;
        }
        cout<<lst<<endl;
    }
    for(int i=1;i<=m;i++)
    {

        cout<<ans[i]<<" ";
    }
    return 0;
}
