#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],flag[200005],zj[200005],ma = 0;
void dfs(int id,int s)
{
    if(s == m + 1)
    {
        int fkbg = zj[1];
        for(int i = 2;i < s;i++)
        {
            fkbg &= zj[i];
        }
        ma = max(ma,fkbg);
        return;
    }
    int maxn = 0,ms = 0;
    for(int i = id + 1;i <= n;i++)
    {
        if(flag[i])
        {
            continue;
        }
        else
        {
            flag[i] = 1;
            zj[s] = a[i];
            dfs(i,s + 1);
            flag[i] = 0;
        }
    }
    return;
}
int main()
{
    memset(flag,0,sizeof(flag));
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    dfs(0,1);
    printf("%d",ma);
    return 0;
}
