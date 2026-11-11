#include<bits/stdc++.h>
using namespace std;
long long n, a, t = 0, ans;
char c;
string s;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> c;
        for(int j = t + 1; j <= t + a; j++){
            s[j] = c;
        }
        t += a;
    }
    cout << t << ' ';
    for(int i = 1; i <= t; i++){
        cout << s[i];
    }
    cout << endl;
    if(t % 2 == 0){
        for(int i = 1; i <= t / 2; i++){
            if(s[i] != s[t - i]){
                ans ++;
            }
        }
    }
    else{
        for(int i = 1; i <= (t - 1) / 2; i++){
            if(s[i] != s[t + 1 - i]){
                ans ++;
            }
        }
    }
    cout << ans;
    return 0;
}
