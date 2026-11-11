#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], maxn, f[200005];
void dfs(int x)
{
    for(int i=f[m-x]+1;i<=n;i++)
    {
        f[x]=i;
        if(x>=2) dfs(x-1);
        else
        {
            int maxx=0x7fffffff;
            for(int j=1;j<=m;j++) maxx&=f[j];
            maxn=max(maxn,maxx);
        }
    }
    if(x==1) cout << maxn << endl;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            maxn=max(maxn,a[i]);
        }
        cout << maxn << endl;
        return 0;
    }
    if(m==n)
    {
        maxn=0x7fffffff;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            maxn&=a[i];
        }
        cout << maxn << endl;
        return 0;
    }
    if(m==n-1)
    {
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++)
        {
            int maxx=0x7fffffff;
            for(int j=1;j<=n;j++) if(i!=j) maxx&=a[j];
            maxn=max(maxn,maxx);
        }
        cout << maxn << endl;
        return 0;
    }
    if(m==2)
    {
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) maxn=max(maxn,i&j);
        cout << maxn << endl;
        return 0;
    }
    for(int i=1;i<=n;i++) cin >> a[i];
    dfs(m);
    return 0;
}
