#include<bits/stdc++.h>
using namespace std;
int a[1000001];
long long minn = 1e9;
int cnt = 0;
int n,d;
void dfs(int x,int y,int sum)
{
    if(x == y)
    {
        if(sum<minn)
        {
            minn = sum;
            cnt = 1;
        }
        else if(sum == minn)cnt++;
        return;
    }
    for(int i = x+1;i<=y;i++)
    {
        if(a[i]-a[x]<=d)
        {
            dfs(i,y,sum + 1);
        }
    }
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i = 1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        long long ans = 0;
        for(int i = 1;i<=n;i++)
        {
            for(int j = i+1;j<=n;j++)
            {
                minn = 1e9;
                cnt = 0;
                dfs(i,j,0);
                if(cnt == 2)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
