#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

string C1, S1, C2, S2;

int Solve(string s){
    int n = s.size(), ans = 0;
    for(int i = n - 1; i >= 0; i--){
        ans = ans * 10 + s[i];
    }
    return ans;
}

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> C1 >> S1 >> C2 >> S2;
    int c1 = Solve(C1), c2 = Solve(C2);
    if(c1 != c2){
        cout << "0000";
    }else{
        cout << 1;
        string tmp;
        tmp.push_back(S1[0]);
        tmp.push_back(S1[1]);
        string tmp2;
        tmp2.push_back(S2[0]);
        tmp2.push_back(S2[1]);
        int s1 = Solve(tmp), s2 = Solve(tmp2);
        if(s1 != s2){
            cout << "000";
            return 0;
        }
        cout << 1;
        if(S1[2] > S2[2])swap(S1[2], S2[2]);
        if(S1[2] == S2[2] - 1 && S1[2] != 'C' || S1[2] == 'A' && S2[2] == 'C'){
            cout << 1;
        }else{
            cout << 0;
        }
        if(S1[2] != S2[2] - 1 || S1[2] == 'C'){
            cout << "0";
            return 0;
        }
        cout << "1";
    }
    return 0;
}
