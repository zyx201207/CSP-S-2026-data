#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 7;
map<int,int> mp;
queue<int> q;
int n,a[N],m;
signed main(){
    int ansi,ansl;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
   // cout << n <<" " << m << endl;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    //for (int i = 1;i <= n;i++){
      // mp[a[i]]++;
  // }
   int s = 0;
   for (int i = -100;i <= 100;i++){
       // cout << i << ":" << mp[i] << endl;
        s += mp[i];
        //cout << i << ":" << s << endl;
   }
    int l = 1,ans = 1,sum = 0;
    for (int i = 2;i <= n;i++){
        sum += (i - l) * (a[i] - a[i - 1]);
        while (sum > m){
              //  cout << "case1" << i <<  " " << sum << endl;
            sum -= (a[i] - a[l]);
            l++;
        }
        if (i - l + 1 > ans){
            ans = i - l + 1;
            ansi = i;
            ansl = l;
        }
    }
    //cout << ansi << " " <<ansl <<endl;
    cout << ans;
    return 0;
}
