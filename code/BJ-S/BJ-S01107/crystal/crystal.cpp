#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
ll a[N],n,m,ans,AB,s[N];
ll F(ll x){
    ll t = m,ai = x-1,cnt = 1;
    while(t >= 0 && ai >= 1){
        if(a[x]-a[ai] <= t){
            t -= a[x]-a[ai];
            cnt++;
        }
        ai--;
    }
    return cnt;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a+1,a+1+n);
    if(n <= 5000){
        for(int i = 1;i <= n;i++)
            ans = max(ans,F(i));
        cout << ans << endl;
        return 0;
    }
    ll c = a[2]-a[1];
    for(int i = 3;i <= n;i++)
        if(a[i]-a[i-1] != c) AB = 1;
    else if(AB == 0){
        s[2] = c;
        for(int i = 3;i <= n;i++)
            s[i] = s[i-1]+c*(i-1);
        //for(int i = 1;i <= n;i++)
        //    cout << s[i] << " ";
        //cout << endl;
        for(int i = 1;i <= n;i++){
            if(s[i] > m){
                cout << i-1 << endl;
                return 0;
            }
        }
        //return 0;
    }
    ll l = 1,r = n;
    while(l <= r){
        ll mid = (l+r)>>1;
        ll xx = F(mid);
        if(xx >= ans){
            //cout << xx << endl;
            ans = xx;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    //cout << '#' << ans << '#' << endl;
    cout << ans << endl;


    return 0;
}
