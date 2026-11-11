#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string now;
ll n;
ll sizee;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 0;i < n;i++) {
        ll x;
        char y;
        cin >> x;
        cin >> y;
        for(int j = 0;j < x;j++) {
            now += y;
        }
        sizee += x;
    }
    ll ann = 0;
    ll k = sizee / 2;
    for(int i = 0;i < k;i++) {
        ll nowx = now[i], nowy = now[i + ((sizee + 2) / 2) - 1];
        if(nowx != nowy) {
            //cout << "x = " << i << " y = " << (int)(i + ((sizee + 2) / 2) - 1) << endl;
            ann++;
        }
    }
    cout << ann << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
