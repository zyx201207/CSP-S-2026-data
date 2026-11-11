#include <bits/stdc++.h>
using namespace std;
const int N=500005;
const int M=300005;
int a[N],last[M],v[N],ans[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(last,0,sizeof(last));
        memset(v,0,sizeof(v));
        for(int j=i;j<=n;j++)
        {
            if(last[a[j]]==0)
            {
                last[a[j]]=j;
            }
            else
            {
                for(int k=last[a[j]];k<j;k++)
                {
                    last[a[k]]=0;
                }
                last[a[j]]=j;
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(last[j]!=0)
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
