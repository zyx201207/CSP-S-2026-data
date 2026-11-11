#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    vector<ll> v(n + 1);
    ll sum = 0;
    string s = " ";
    for(int i = 1; i <= n; i ++)
    {
        ll a; string b;
        cin >> a >> b;
        sum += a;
        v[i] = a;
        s = s + b;
    }
    ll ans = 0;
    for(int i = 1, j = n; i <= j; i ++, j --)
    {
        if(v[i] <= v[j] && s[i] == s[j])
        {
            v[j] = v[j] - v[i];j ++;
        }else if(v[i] <= v[j] && s[i] != s[j])
        {
            ans += v[i];
            v[j] = v[j] - v[i];
            j ++;
        }else if(v[i] > v[j] && s[i] == s[j])
        {
            v[i] = v[i] - v[j];i --;
        }else
        {
            ans += v[j];
            v[i] = v[i] - v[j];
            i --;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
}
