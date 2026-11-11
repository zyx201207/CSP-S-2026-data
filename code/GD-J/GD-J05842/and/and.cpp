#include<bits/stdc++.h>
int m = 0,n = 0;
int a[200005] = {0};
int mx = 0;
void dfs(int,int,int);
int main()
{
    std::freopen(&"and.in"[0],&"r"[0],stdin);
    std::freopen(&"and.out"[0],&"w"[0],stdout);
    std::scanf(&"%d %d"[0],&n,&m);
    for(int i = 1;i <= n;i = i + 1)
    {
        std::scanf(&"%d"[0],&a[i]);
    }
    dfs(0,0,0);
    std::printf(&"%d"[0],mx);
    return 0;
}
void dfs(int step,int ans,int num)
{
    if(step > n || n - step < m)
    {
        return;
    }
    if(num == m)
    {
        mx = std::max<int> (mx,ans);
        return;
    }
    if(ans == 0)
    {
        dfs(step + 1,a[step + 1],num + 1);
    }
    else
    {
        dfs(step + 1,ans & a[step + 1],num + 1);
    }
    if(n - step > m)
    {
        dfs(step + 1,ans,num);
    }
    return;
}