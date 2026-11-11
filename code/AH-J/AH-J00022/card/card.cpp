#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool f[300010];
int b[200010];
int ans[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    memset(f,false,sizeof(f));
    int tot=1;
    for(int i=1;i<=n;i++)
    {
        if(!f[a[i]])
        {
            b[tot]=a[i];
            tot++;
            ans[a[i]]++;
            f[a[i]]=true;
            continue;
        }
        tot=1;
        b[tot]=a[i];
        ans[a[i]]++;
        f[a[i]]=false;
    }
    for(int i=1;i<=m;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}
