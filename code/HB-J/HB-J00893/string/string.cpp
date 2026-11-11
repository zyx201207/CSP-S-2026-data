#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool is_hw(string a){
    string a1;
    for (int i = s.size() - 1; i >= 0; i--){
        a1 += a[i];
    }
    if (a1 == a){
        return 1;
    }
    return 0;
}
string fz(string n){
    string a1;
    for (int i = n.size() - 1; i >= 0; i--){
        a1 += n[i];
    }
    return a1;
}
bool least_change(string a){
    int len = a.size();
    int cnt = 0;
    string a1;
    if (len % 2 == 0){
        for (int i = 0; i < (len / 2); i++){
            a1 += a[i];
        }
        string a2 = fz(a1);
        for (int i = (len / 2); i < len; i++){
            if (a[i] != a2[i - (len / 2)]){
                cnt++;
            }
        }
    }else{
        for (int i = 0; i < (len / 2); i++){
            a1 += a[i];
        }
        string a2 = fz(a1);
        for (int i = (len / 2) + 1; i < len; i++){
            if (a[i] != a2[i - (len / 2)]){
                cnt++;
            }
        }
    }
    return cnt;
}
int main (){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int m;
        string s1;
        cin >> m >> s1;
        for (int j = 1; j <= m; j++){
            s = s + s1;
        }
    }
    if (is_hw(s)){
        cout << 0;
    }else{
        cout << least_change(s);
    }
    return 0;
}
