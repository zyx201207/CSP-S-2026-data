#include <bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","r",stdout);
    cin >> a >> s1 >> b >>s2;
    if(a != b){
        cout << "0000";
        return 0;
    }
    cout << 1;

    int n = (int)(s1[0] - '0') * 10 + (int)(s1[1] - '0');
    int m = (int)(s2[0] - '0') * 10 + (int)(s2[1] - '0');
    if(n != m){
        cout << "000";
        return 0;
    }
    cout << 1;

    int c1 = s1[2] - 'A' + 1;
    int c2 = s2[2] - 'A' + 1;
    if((c1 > 3 && c2 <= 3) || (c1 <= 3 && c2 > 3)){
        cout << "00";
        return 0;
    }
    cout << 1;
    if(abs(c1 - c2) != 1)cout << 0;
    else cout << 1;
    return 0;
}
