#include <bits/stdc++.h>
using namespace std;
#define I return
#define AK 0
#define IOI 
int a[500005], x[300005], y[300005];
int is[500005];
int l[300005], r[300005];
int ans[500005];
int vis[500005];
void link(int p, int q)
{
    l[q] = p;
    r[p] = q;
}
int main()
{
    /*
    wu ri san xing wu shen:
    kai long long hu?
    xie freopen hu?
    guan tong bu liu hu?
    */
   //zhe ti shi jia zuo fa QwQ
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        for(int j = i; j <= n; j++)
        {
            vis[a[j]]++;
            if(x[a[j]])
            {
                for(int k = x[a[j]]; k < j; k++)
                {
                    vis[a[k]]--;
                }
            }
            x[a[j]] = j;
        }
        for(int i = 1; i <= m; i++)
        {
            if(vis[i]) ans[i]++;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cout<<ans[i]<<' ';
    }
    I AK IOI;
}//mu luogu uid is:1512077