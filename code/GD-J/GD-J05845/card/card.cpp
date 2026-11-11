#include <bits/stdc++.h>
using namespace std;
int in[500007];
int gg[500007];
int n,m;
int a[500007];
long long ans[300007];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        if(gg[a[i]] == 0)
        {
            gg[a[i]] = i;
        }
        else
        {
            in[gg[a[i]]] = i;
            gg[a[i]] = i;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int j = i;
        while(j <= n)
        {
            while(in[j] != 0)
            {
                j = in[j];
            }
            ans[a[j]]++;
            j++;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        printf("%lld ",ans[i]);
    }
    return 0;
}
