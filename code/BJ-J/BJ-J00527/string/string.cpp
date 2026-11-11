#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
typedef long long ll;

int n, a[N], cha, ans, id, f;

ll L, sum;

string s1, s2;

char c[N];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        L += a[i];
    }
    if (L & 1){
        L--;
        f = 1;
    }
    L >>= 1;
    for (int i = 1; i <= n; i++){
        sum += a[i];
        if (sum >= L){
            id = i;
            if (sum > L) cha = sum - L;
            break;
        }
    }
    for (int i = 1; i <= id; i++){
        if (i != id){
            for (int j = 1; j <= a[i]; j++) s1.push_back(c[i]);
        }else{
            for (int j = 1; j <= a[i] - cha; j++) s1.push_back(c[i]);
        }
    }
    if (!cha){
        for (int i = id + 1; i <= n; i++){
            if (i == id + 1){
                if (f){
                    for (int j = 2; j <= a[i]; j++) s2.push_back(c[i]);
                }
            }else{
                for (int j = 1; j <= a[i]; j++) s2.push_back(c[i]);
            }
        }
    }else{
        for (int i = id; i <= n; i++){
            if (i == id){
                for (int j = a[i] - cha + 2; j <= a[i]; j++) s2.push_back(c[i]);
            }else{
                for (int j = 1; j <= a[i]; j++) s2.push_back(c[i]);
            }
        }
    }
    reverse(s1.begin(), s1.end());
    for (int i = 0; i < s1.size(); i++)
        if (s1[i] != s2[i]) ans++;
    cout << ans << '\n';
    return 0;
}
