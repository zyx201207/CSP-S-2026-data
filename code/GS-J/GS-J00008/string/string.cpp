#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,a[N],sum[N];
char c[N];
long long l,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie();
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i];
        l += a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = 1;i <= l && !(i == l + 1 - i);i++)
    {
        int j = l + 1 - i;
        char ci = 'R',cj = 'R';
        int l = 1,r = n;
        for(;l <= r;l++,r--)
        {
            if(sum[l] >= i && sum[l - 1] <= i)
                ci = c[l];
            if(sum[r] >= j && sum[r - 1] <= j)
                cj = c[r];
            if(ci != 'R' && cj != 'R')
                break;
        }
        if(ci != cj)
            ans++;
    }
    cout << ans;
    return 0;
}
