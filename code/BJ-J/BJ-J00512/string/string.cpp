#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    vector<char> s;
    s.push_back('#');
    cin >> n;
    for (int i = 1; i <= n; i++){
        int a;
        char c;
        cin >> a >> c;
        while (a--){
            s.push_back(c);
        }
    }
    n = s.size() - 1;
    int l, r;
    if (n % 2 == 0){
        l = n / 2;
        r = n / 2 + 1;
    }else{
        l = (n + 1) / 2;
        r = l;
    }
    int cnt = 0;
    while (l >= 1 && r <= n){
        if (s[l] != s[r]){
            cnt++;
        }
        l--;
        r++;
    }
    cout << cnt;
    return 0;
}
