#include <bits/stdc++.h>
using namespace std;
int n,m,ans = 0,a[100005],s[100005];
void dfs(int sp,int now)
{
    if(sp>m)
    {
        int re = 2147483647;
        for(int i = 1;i<=m;i++)
        {
            re = (re&a[i]);
            cout << a[i] << " ";
        }
        cout << endl;
        ans = max(ans,re);
        return;
    }
    for(int i = now+1;i<=n-m+sp;i++)
    {
        a[sp+1] = s[i];
        dfs(sp+1,i);
        a[sp+1] = 0;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> s[i];
    }
    dfs(0,0);
    cout << ans << endl;
    return 0;
}