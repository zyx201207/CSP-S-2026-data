#include <bits/stdc++.h>

using namespace std;
int a[500005];
int ans[300005],last[300005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        last[a[i]]=i;
    }
    for(int t=1;t<=n;t++)
    {
        for(int i=t;i<=n;)
        {
            ans[a[i]]++;
            i=last[a[i]]+1;
        }
    }
    for(int i=1;i<=m;i++)
        printf("%d ",ans[i]);
}
