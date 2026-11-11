#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,len;
pair<string,int> a[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i].second >> a[i].first;
        len += a[i].second;
    }
    for (int t = 1;t <= (len+1)/2;t++)
    {
        int sum1 = 0,sum2 = 0,p1 = 1,p2 = n;
        while (sum1 < t)
        {
            sum1 += a[p1].second;
            p1++;
        }
        while (sum2 < t)
        {
            sum2 += a[p2].second;
            p2--;
        }
        if (a[p1-1].first != a[p2+1].first) ans++;
    }
    cout << ans;
    return 0;
}