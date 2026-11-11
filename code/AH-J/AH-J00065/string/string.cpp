#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
ll n, m;
ll a[N];
char s[N];
ll ans = 0;
int main(){
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> s[i];
        m += a[i];
    }
 /*   ll mid = -1,res =0;
    for(int i = 1;i <= n;i++){
        res += a[i];
        if(res >= m/2){mid = i;break;}
    }*/

    if(m <= 2000006){
        string sss = "";
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= a[i];j++)    sss += s[i];
        }
        ll ans = 0;
        for(int i = 0, j = m-1;i <= j;i++,j--){
            if(sss[i] != sss[j])    ans++;
        }
        cout << ans << endl;
        return 0;
    }
    ll l = a[1], r = a[n],i = 1, j = n;
    char ll = s[1], rr = s[n];
    while(i < j){
        if(ll != rr)
            ans += min(l, r);
      //  cout << ll <<' ' <<rr << ' '<< ans << endl;
        if(l > r)  {l -= r, r = a[--j], rr = s[j];}
        else if(r > l){r -= l, l = a[++i], ll = s[i];}
        else    {l = a[++i], ll = s[i], r = a[--j], rr = s[j];}
      //  cout << l << ' ' << r<< endl;
    }
    cout << ans <<endl;
    return 0;
}
