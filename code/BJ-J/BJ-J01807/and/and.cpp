#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[1000001];
long long ans = 0;
void dfs(int x,int cnt,long long sum)
{
    if(x>n)
    {
        if(cnt == m)ans = max(sum,ans);
        return;
    }
    if(cnt<m)
    {
        dfs(x + 1,cnt + 1,sum & a[x]);
    }
    dfs(x + 1,cnt,sum);

}
int main()
{
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    long long maxn = 0;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        maxn = max(a[i],maxn);
    }
    long long sum1 = a[1];
    for(int i = 2;i<=n;i++)sum1&=a[i];
    if(m == 1)
    {
        cout<<maxn<<endl;
        return 0;
    }
    if(m == 2)
    {
        for(int i = 1;i<=n;i++)
        {
            for(int j = i+1;j<=n;j++)ans = max(a[i] & a[j],ans);
        }
        cout<<ans<<endl;
        return 0;
    }
    if(m == n)
    {
        cout<<sum1<<endl;
        return 0;
    }
    if(m == n-1)
    {
        for(int i = 1;i<=n;i++)ans = max(~(sum1^a[i]),ans);
        cout<<ans<<endl;
        return 0;
    }
    dfs(1,0,2147483647);
    cout<<ans<<endl;
    return 0;
}
