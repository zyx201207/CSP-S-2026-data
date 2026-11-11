#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200005], ans = 0;
map<long long, long long> mp;
vector<long long> v;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    if(n <= 20){
        for(long long i = 1;i <= 1 << n;i ++){
            long long num = i, v = 0, l = (1 << 21) - 1, r = 1;
            while(num){
                if(num & 1){
                    v ++;
                    l &= a[r];
                }
                r ++;
                num /= 2;
            }
            if(v == m){
                ans = max(ans, l);
            }
        }
        cout << ans;
    }else if(m == 1){
        sort(a + 1, a + n + 1);
        cout << a[n];
    }else if(m == n){
        ans = (1 << 21) - 1;
        for(int i = 1;i <= n;i ++){
            ans &= a[i];
        }
        cout << ans;
    }else if(m == 2){
        sort(a + 1, a + n + 1);
        for(int i = n - 1;i >= 1;i --){
            for(int j = n;j >= i + 1; j --){
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
    }else{
        for(int i = 1;i <= n;i ++){
            if(mp.find(a[i]) == mp.end()){
                v.push_back(a[i]);
            }
            mp[a[i]] ++;
        }
        sort(v.begin(), v.end());
        for(int i = v.size() - 1;i >= 0;i --){
            if(mp[v[i]] >= m){
                cout << v[i];
                break;
            }
        }
    }
    return 0;
}
