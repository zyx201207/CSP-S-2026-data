#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll n,ans = 0;
int maxx = INT_MIN;
ll cnt = 0,cnt2 = 0;
struct node
{
    int sum;
    char c;
}a[N];
string s1 = "",s2 = "",l = "";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].sum >> a[i].c,maxx = max(maxx,a[i].sum);
    if(n * maxx > 100000000)
    {
        ll ans = 0;
        if(n & 1)
        {
            for(int i = 1,j = n;i <= n / 2,j >= n / 2 + 2;i++,j--)
            {
                if(a[i].c != a[j].c) ans += min(a[i].sum,a[j].sum);
            }
        }
        else
        {
            for(int i = 1,j = n;i <= n / 2,j >= n / 2 + 1;i++,j--)
            {
                if(a[i].c != a[j].c) ans += min(a[i].sum,a[j].sum);
            }
        }
        cout << ans;
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        cnt += a[i].sum;
        for(int j = 1;j <= a[i].sum;j++) l += a[i].c;
    }
    int mid = cnt + 1 >> 1;
    if(cnt & 1)
    {
        for(int i = 0;i <= mid - 2;i++) s1 += l[i];
        for(int i = l.size() - 1;i >= mid;i--) s2 += l[i];
    }
    else
    {
        for(int i = 0;i < mid;i++) s1 += l[i];
        for(int i = mid;i <= l.size();i++) s2 += l[i];
    }
    for(int i = 0;i < s1.size();i++) if(s1[i] != s2[i]) ans++;
    cout << ans;
    return 0;
}
