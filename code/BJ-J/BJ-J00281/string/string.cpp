#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, tot1, tot2;
ll len;
pair<int, char> a[maxn], a1[maxn], a2[maxn];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        char tmp;
        cin >> a[i].first >> a[i].second;
        len += a[i].first;
    }
    ll cnt = 0;
    for(int i = 1; i <= n; i ++) {
        bool flag = cnt + 1 <= len / 2;
        cnt += a[i].first;
        if(cnt <= len / 2 && flag)
            a1[++ tot1] = a[i];
        else if(cnt > len / 2 && !flag) {
            if(len % 2 && cnt - a[i].first + 1 == (len + 1) / 2)
                a2[++ tot2] = {a[i].first - 1, a[i].second};
            else
                a2[++ tot2] = a[i];
        }
        else if(cnt > len / 2 && flag) {
            if(len % 2) {
                if(cnt == (len + 1) / 2)
                    a1[++ tot1] = {a[i].first - 1, a[i].second};
                else
                    a1[++ tot1] = {len / 2 - cnt + a[i].first, a[i].second}, a2[++ tot2] = {cnt - len / 2 - 1, a[i].second};
            }
            else
                a1[++ tot1] = {len / 2 - cnt + a[i].first, a[i].second}, a2[++ tot2] = {cnt - len / 2, a[i].second};
        }
    }
    reverse(a2 + 1, a2 + tot2 + 1);//string str1,str2;for(int i=1;i<=tot1;i++)while(a1[i].first--)str1+=a1[i].second;cerr<<'\n';for(int i=1;i<=tot2;i++)while(a2[i].first--)str2+=a2[i].second;cerr<<'\n';ll r=0;for(int i=0;i<str1.size();i++)r+=str1[i]!=str2[i];cerr<<r<<'\n';return 0;
    ll cnt1 = 0, cnt2 = 0, ans = 0;
    for(int i = 1, j = 1; i <= tot1; i ++) {
        cnt1 += a1[i].first;
        if(cnt2 >= cnt1 && a1[i].second != a2[j-1].second) {
            ans += a1[i].first;
            continue;
        }
        if(cnt1 > cnt2 && a1[i].second != a2[j-1].second)
            ans += cnt2 - cnt1 + a1[i].first;
        while(cnt2 < cnt1) {
            cnt2 += a2[j].first;
            if(cnt2 > cnt1) {
                ++ j;
                break;
            }
            else {
                if(a1[i].second != a2[j].second)
                    ans += a2[j].first;
                ++ j;
            }
        }
        if(cnt2 > cnt1 && a1[i].second != a2[j-1].second)
            ans += cnt1 - cnt2 + a2[j-1].first;
    }
    cout << ans << '\n';
    return 0;
}
