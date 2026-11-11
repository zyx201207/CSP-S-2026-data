#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5+5;
int a[N];
char c[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i]>>c[i];
    int l = 1,r = n; int ans = 0ll;
    while(l<r)
    {
        if(a[l]<a[r])
        {
            if(c[l] != c[r]) ans += a[l];
            a[r] -= a[l]; l++;
        }
        else if(a[l] == a[r])
        {
            if(c[l] != c[r]) ans += a[l];
            l++,r--;
        }
        else
        {
            if(c[l] != c[r]) ans += a[r];
            a[l] -= a[r]; r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
