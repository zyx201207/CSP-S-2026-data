#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5 + 10;
struct str{
    ll num;
    char c;
}a[maxn];
ll change_back(vector<str> x1, vector<str> x2){
    int i = 0;
	ll ans = 0;
    while(x2.size() > 0 && i < x1.size()){
        if(x1[i].num == x2.back().num){
            if(x1[i].c != x2.back().c) ans += x1[i].num;
            x2.pop_back();
        }
        else if(x1[i].num < x2.back().num){
            if(x1[i].c != x2.back().c) ans += x1[i].num;
            x2.back().num -= x1[i].num;
        }
        else{
            while(x2.size() > 0){
                if(x1[i].num > x2.back().num){
                    if(x1[i].c != x2.back().c) ans += x2.back().num;
                    x1[i].num -= x2.back().num;
                    x2.pop_back();
                } else {
                    i--;
                    break;
                }
            }
        }
        i++;
    }
    return ans;
}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int n, pos;
    ll sum = 0, tmp = 0;
    char qwer;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].num >> a[i].c;
        sum += a[i].num;
    }
    vector<str> s1, s2;
    for(pos = 1; pos <= n; pos++){
        int i = pos;
        if(tmp + a[i].num == sum / 2){
            s1.push_back(a[i]);
            pos++;
            break;
        }
        if(tmp + a[i].num > sum / 2){
            s1.push_back({sum / 2 - tmp, a[i].c});
            a[i].num -= (sum / 2 - tmp);
            break;
        }
        s1.push_back(a[i]);
    }
    if(sum % 2 != 0 && a[pos].num == 1) pos++;
    for(int i = pos; i <= n; i++) s2.push_back(a[i]);
    if(sum % 2 != 0) s2[0].num--;
    /*
    for(auto it : s1) cout << it.num << ' ' << it.c << ' ';
    for(auto it : s2) cout << it.num << ' ' << it.c << ' ';
    */
    ll ans1 = change_back(s1, s2), ans2 = change_back(s2, s1);
    cout << min(ans1, ans2);
    return 0;
}

