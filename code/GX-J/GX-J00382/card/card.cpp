#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
    }
    vector<int> last(m+1,0);
    vector<int> f(n+2,0);
    vector<int> dis(n+2,0);
    for(int i=n;i>=1;i--)
    {
        int v=a[i];
        f[i]=last[v];
        int L=i;
        int R=f[i] ? f[i]-1 : n;
        dis[L]++;
        dis[R+1]++;
        last[v]=i;
    }
    vector<int> sum(n+1,0);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+dis[i];
    }
    vector<int> ans(m+1,0);
    for(int i=1;i<=n;i++)
    {
        ans[a[i]]=sum[i];
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}

