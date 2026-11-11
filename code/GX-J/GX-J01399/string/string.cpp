#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    int cnt = 0;
    string s = "";
    vector<int> a(n),c(n);
    for(int i = 0;i < n;i++){
        cin >> a[i] >> c[i];
        for(int j = 1;j <= a[i];j++){
            s.push_back(c[i]);
        }
    }if(n <= 1){
        cout << "0\n";
    }int gm = (a[0] + a[1])% 2 == 1 ? (a[0] + a[1])/ 2 + 1 : (a[0] + a[1])/ 2;
    for(int i = 0;i < gm;i++){
        if(s[i] != s[gm - i]){
            cnt++;
            s[i] = s[gm - i];
        }
    }cout << cnt << "\n";
    return 0;
}
