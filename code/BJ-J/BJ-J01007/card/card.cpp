#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],t[N],ans[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        t[a[i]]++;
    if(m<=2)
    {
        int e=a[n];
        for(int i=1;i<=n;i++)
        {
            ans[e]++;
            if(a[i]!=e)ans[a[i]]++;
        }
        printf("%d %d",ans[1],ans[2]);
    }
    else
    {
        for(int i=1;i<=n;i++)
            t[a[i]]=i;
        for(int i=1;i<=m;i++)
            printf("%d ",t[i]);
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
