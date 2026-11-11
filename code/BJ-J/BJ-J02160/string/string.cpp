#include<bits/stdc++.h>
using namespace std;
const int N = 200050;
using ll = long long;
struct st
{
    ll len;
    char val;
};
st a[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].len >> a[i].val;
    }
    ll l = 1,r = n;
    ll ans = 0;
    while(l < r)
    {
        if(a[l].val == a[r].val)
        {
            if(a[l].len == a[r].len){
                l++;
                r--;
            }
            else if(a[l].len < a[r].len)
            {
                a[r].len -= a[l].len;
                l++;
            }
            else if(a[l].len > a[r].len)
            {
                a[l].len -= a[r].len;
                r--;
            }
        }
        else
        {
            if(a[l].len == a[r].len){
                ans += a[l].len;
                l++;
                r--;
            }
            else if(a[l].len < a[r].len)
            {
                ans += a[l].len;
                a[r].len -= a[l].len;
                l++;
            }
            else if(a[l].len > a[r].len)
            {
                ans += a[r].len;
                a[l].len -= a[r].len;
                r--;
            }

        }
    }
    cout << ans;
    return 0;
}
