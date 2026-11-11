#include<bits/stdc++.h>
using namespace std;
//vector<char> a = {};
int n;
int cnt = 0;
string s = "";
int main() {
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >>n;
    for(int i  =0 ;i < n;i++) {
        int num;
        char c;
        cin >> num >> c;
        for(int i = 0 ;i < num;i++) {
            //a.push_back(c);
            s += c;
        }

    }
    int L = 0;
    int R = s.size() -1;
    while(L < R) {
        if(s[L] != s[R]) {
            cnt++;
            s[R] = s[L];
        }
        R--;
        L++;
        //cout << L <<' ' << R <<endl;
    }
    cout << cnt;
    return 0;

}
