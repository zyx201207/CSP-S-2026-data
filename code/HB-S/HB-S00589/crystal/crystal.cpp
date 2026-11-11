#include<bits/stdc++.h>
using namespace std;

int n, ans, b[1001];
bool flag[1001];
long long m, a[500002];

void dfs(int cnt)
{
    if(cnt > m) 
    {
        for(int i=1;i<=n;i++) a[i] += b[i];
        int time = 0;
        sort(a+1, a+n+1);
        for(int i=1;i<=n;i++)
        {
            if(a[i] == a[i-1]) time++;
            else time = 0;
        }
        ans = max(ans, time+1);
        for(int i=1;i<=n;i++) a[i] -= b[i];
    }
    for(int i=0;i<=m;i++)
    {
        if(!flag[i])
        {
            flag[i] = 1;
            b[cnt] = i;
            dfs(cnt + 1);
            flag[i] = 0;
        }
    }
    return;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m ;
    for(int i=1;i<=n;i++) cin >> a[i];
    dfs(1);
    cout << ans;
    return 0;
}