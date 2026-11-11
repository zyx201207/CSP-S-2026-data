#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
struct T
{
    int num,pre;
}a[N];
int fa[N],cnt[N],ans[N],tmp[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].num;
        a[i].pre=fa[a[i].num];
        fa[a[i].num]=i;
        cnt[a[i].num]++;
    }
    for (int i=1;i<=n;i++)
    {
        cnt[a[i-1].num]--;
        for (int j=1;j<=m;j++)
            tmp[j]=cnt[j];
        for (int j=i;j<=n;j++)
        {
            if (a[j].pre>=i)
            {
                int l=a[j].pre,r=j-1;
                for (int k=l;k<=r;k++)
                {
                    int x=a[k].num;
                    if (tmp[x]>=1) tmp[x]--;
                }
            }
        }
        for (int j=1;j<=m;j++)
        {
            if (tmp[j]>0)
            {
                ans[j]++;
                //cout<<j<<" ";
            }
        }
    }
    for (int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}
