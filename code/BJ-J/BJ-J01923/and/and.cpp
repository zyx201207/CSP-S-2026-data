#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n, m;
int a[maxn];
int ans;
void dfs(int i, int use, int sum)
{
    if(i>n)
    {
        if(use==m) ans=max(ans, sum);
        return ;
    }
    if(use==0) dfs(i+1, use+1, a[i]);
    else dfs(i+1, use+1, sum&a[i]);
    dfs(i+1, use, sum);
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >>n >>m;
    for(int i=1; i<=n; ++i)
    {
        cin >>a[i];
    }
    ans=0;
    dfs(1, 0, 0);
    cout <<ans;
    return 0;
}