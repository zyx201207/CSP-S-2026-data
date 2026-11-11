#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
ll nn;
ll a[500005], m, s, cnt=0;
bool ck(int n){
    s = 0;
    for(int i = 1; i <= n; i++)
    {
        s += a[n] - a[i];
        if(s > m){
            //cout << s << '\n' << m << '\n';
            return false;
        }
    }
    return true;
}
bool ck2(int k){
    s = 0;
    for(int i = k; i < nn; i++)
    {
        s += a[nn] - a[i];
        if(s > m){
            //cout << s << '\n' << m << '\n';
            return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> nn >> m;
    for(int i = 1; i <= nn; i++)
    {
        cin >> a[i];

    }
    sort(a + 1, a + nn + 1);
    ll l = 1, midl=1, midg=1, r = nn;
    while(l < r){
        midl = (l + r) / 2 + 1;
        if(ck(midl)){
            if(s == m) break;
            l = midl + 1;
        }else{
            r = midl - 1;
        }
        if(cnt == 1e3) break;
        cnt++;
    }
    if(midl == nn){
        cout << midl;
        return 0;
    }
    l = 1, r = nn;
    while(l < r){
        midg = (l + r) / 2 - 1;
        if(ck2(midg)){
            if(s == m) break;
            r = midg - 1;
        }else{
            l = midg + 1;
        }
        if(cnt == 1e3) break;
        cnt++;
    }
    cout << max(midl, nn - midg + 1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
