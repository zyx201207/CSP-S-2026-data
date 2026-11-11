#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[300001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        ans[a[i]]++;
        ans[a[n]]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}