#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005],ans;
bool pcnt(int x)
{
    int res = 0;
    while(x)
    {
        if(x & 1) res++;
        x >>= 1;
    }
    return res == m;
}
int check(int x)
{
    int ret = (int)pow(2,30) - 1,i = 1;
    while(x)
    {
        if(x & 1)
            ret &= a[i];
        i++;
        x >>= 1;
    }
    return ret;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < (1 << n);i++)
        if(pcnt(i))
            ans = max(ans,check(i));
    cout << ans;
    return 0;
}
