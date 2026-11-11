#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out","w",stdout);
    string s;
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i ++){
        string c;
        ll a;
        cin >> a;
        cin >> c;
        for(ll j = 1; j <= a; j ++)s = s + c;
    }
    ll sum = s.size() / 2;
    int sum2 = sum;
    for(ll i = 0; i < sum2; i ++){
        if(s[i] == s[s.size()-i-1])sum --;
        //cout << s[i] << " " << s[s.size()-i-1] << " " << i << endl;
    }
    cout << sum;
    return 0;
}
