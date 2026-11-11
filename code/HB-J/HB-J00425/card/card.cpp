#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[300005],gh[300005],ans[300005];
int main()
{
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(b,0,sizeof(b));
        memset(gh,0,sizeof(gh));
        for(int j=i;j<=n;j++)
        {
            if(b[a[j]]==1)
            {
                b[a[j]]=0;
                for(int k=gh[a[j]];k<j;k++)
                {
                    gh[a[k]]=0;
                    b[a[k]]=0;
                }
                gh[a[j]]=j;
            }
            b[a[j]]++;
            gh[a[j]]=j;
        }
        for(int g=1;g<=m;g++)
        {
            if(b[g]==1) ans[g]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
