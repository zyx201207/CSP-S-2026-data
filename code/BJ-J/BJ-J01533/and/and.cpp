/*
choose m numbers that makes the value of and greatly
sort in a special way and choose the first m numbers
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, m, cnt;
ll a[200010];

string f(ll u){
    if(u == 0) return "0";

    string s = "";

    while(u){
        if(u % 2) s += '1';
        else s += '0';
        u /= 2;
    }

    reverse(s.begin(), s.end());

    return s;
}

bool flag(ll x){
    string s = f(x);

    for(ll i = 1; i < s.size(); i++){
        if(s[i] == '1') return true;
    }

    return false;
}

/*
bool cmp1(ll x, ll y){
    string s = f(x);
    string t = f(y);

    deque<char> q1, q2;

    for(int i = 0; i < s.size(); i++) q1.push_back(s[i]);
    for(int i = 0; i < t.size(); i++) q2.push_back(t[i]);

    while(q1.size() && q2.size()){
        if(q1.size() != q2.size()) return q1.size() > q2.size();
        else{
            q1.pop_front(), q2.pop_front();

            while(q1.front() == '0') q1.pop_front();
            while(q2.front() == '0') q2.pop_front();
        }
    }

    return q1.size() > q2.size();
}
*/

bool cmp(ll x, ll y){
    return x > y;
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for(ll i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1, cmp);

//    for(ll i = 1; i <= n; i++) cout << a[i] << endl;

    ll ans = 2147483647;

    for(ll i = 1; cnt < m; i++){
        if(cnt == 0 && !flag(a[i])) continue;
        else ans &= a[i], cnt++;
    }

    cout << ans;

    return 0;
}
