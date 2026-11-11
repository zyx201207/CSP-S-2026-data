#include <bits/stdc++.h>
using namespace std;

long long n, m, half, ans, x, y, b;
long long k = 1, cnt = 0;
bool f = 0;
string s, s2;
long long a[500010];

int main(){

    freopen("string.in", "r", stdin);
    freopen("string.out", " w", stdout);
    cin >> n;
    while(k <= n){
        cin >> a[k] >> s[k];
        m += a[k];
        k++;
    }
    if(m % 2 ==1){
        f = 1;
    }
    cout << f <<endl;
    for(int i = 1; i <= n; i++){
        half += a[i];
        cout <<half<<" "<<m/2<<endl;
        if(half == m / 2){
            if(f == 1){
                if(a[i + 1] == 1){
                    x = i;
                    y = i + 2;
                }
                else{
                    x = i;
                    y = i + 1;
                    a[i + 1]--;
                }
            }
            else{
                x = i;
                y = i + 1;
            }
            break;
        }
        else if(half > m / 2){
                if(f == 1){
                    if(half == m / 2 + 1){
                        x = i;
                        y = i + 1;
                        a[i]--;
                    }
                    else{
                        if(half - m / 2 - 1 == a[i] - (half - m / 2)){
                            x = i - 1;
                            y = i + 1;
                            a[i] = 0;
                        }
                        else{
                            if(half - m / 2 - 1 < a[i] - (half - m / 2)){
                                x = i - 1;
                                y = i;
                                a[i] = a[i] - (half - m / 2);
                            }
                            else{
                                x = i;
                                y = i + 1;
                                a[i] = half - m / 2 - 1;
                            }
                        }
                    }
                }
            else{
                if(half - m / 2 > a[i] - (half - m / 2)){
                    x = i;
                    y = i + 1;
                    a[i] = half - m / 2;
                }
                else if(half - m / 2 < a[i] - (half - m / 2)){
                    x = i - 1;
                    y = i;
                    a[i] = a[i] - (half - m / 2);
                }
                else{
                    x = i - 1;
                    y = i + 1;
                    a[i] = 0;
                }
            }
            break;
        }
    }
    while(x >= 1 && y <= k){
        if(s[x] != s[y]){
            ans += min(a[x], a[y]);
            b = a[x];
            a[x] -= min(a[x], a[y]);
            a[y] -= min(b, a[y]);
            if(a[x] == 0){
                x--;
            }
            if(a[y] == 0){
                y++;
            }
        }
        else{
            b = a[x];
            a[x] -= min(a[x], a[y]);
            a[y] -= min(b, a[y]);
            if(a[x] == 0){
                x--;
            }
            if(a[y] == 0){
                y++;
            }
        }
    }
    cout << ans;
    return 0;
}
