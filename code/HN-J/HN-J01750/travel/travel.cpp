#include<bits/stdc++.h>

using namespace std;
using ll = long long;

string a, b, c, d;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    if(a != c){
        cout << "0000";
        return 0;
    }
    if(b[0] + b[1] != d[0] + d[1]){
        cout << "1000";
        return 0;
    }
    if((b[2] < d[2] && b[2] == 'C') || (d[2] < b[2] && d[2] == 'C')){
        cout << "1100";
        return 0;
    }
    if(abs(0 + b[2] - d[2]) != 1){
        cout << "1110";
    } else{
        cout << "1111";
    }
    return 0;
}
