#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w+", stdout);
    int n, cnt = 0;
    cin >> n;
    vector <char> v;
    for(int i = 0; i < n; i++) {
        int c1;
        char c2;
        cin >> c1 >> c2;
        for(int j = 0; j < c1; j++) {
            v.push_back(c2);
        }
    }
    vector <char> lv, rv, vv;
    for (int i = 0; i < (int)v.size(); i++) {
        vv.push_back(v[i]);
    }
    if (v.size() % 2 != 0) {
        vv.erase(vv.begin() + ((vv.size() - 1) / 2) + 1);
    }
    for(int i = 0; i < (int)v.size(); i++) {
        if(i <= vv.size() / 2 - 1) {
            lv.push_back(vv[i]);
        } else {
            rv.push_back(vv[i]);
        }
    }
    for(int i = 0; i < (int)lv.size(); i++) {
        if(lv[i] != rv[1]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    fclose(stdin);
    fclose(stdout);
}
