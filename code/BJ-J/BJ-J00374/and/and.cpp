#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int ans;
int maxx;
int a[200010];
void solve(int dep,int idx)
{
    if (dep==(m-1))
    {
        return;
    }
    for (int i=idx;i<=n;i++)
    {
        maxx=maxx&(a[i]);
        solve(dep+1,i+1);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans=max(ans,a[i]);
    }
    if (m==n)
    {
        ans=a[1];
        for (int i=2;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if (m==2)
    {
        ans=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if (n<=20)
    {
        ans=0;
        for (int i=1;i<=n;i++)
        {
            maxx=a[i];
            solve(1,i+1);
            ans=max(ans,maxx);
        }
        cout<<ans;
        return 0;
    }
    cout<<ans;
    return 0;
}
