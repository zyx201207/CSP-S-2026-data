#include<bits/stdc++.h>
using namespace std;
int a[500010],ans[300010];
bool f[500010];
int n,m;
void x(int s)
{
    for(int i = 1;i <= n;i++)
    {
        f[i] = 0;
    }
    for(int i = s;i <= n;i++)
    {
        if(f[a[i]] == 1)
        {
            for(int j = s;j < i;j++)f[j] = 0;
        }
        f[a[i]] = 1;
    }
    for(int i = 1;i <= n;i++)
    {
        if(f[i])ans[i] ++;
    }
    return;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        x(i);
    }
    for(int i = 1;i <= m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}