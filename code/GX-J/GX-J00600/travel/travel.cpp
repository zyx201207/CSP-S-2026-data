#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    int c1 = 0, c2 = 0;
    string a , b;

    cin >> c1 >> a >> c2 >> b;
    if(c1 == c2)
        cout << 1;
    else
        cout << 0;

    if(a.substr(0, 2) == b.substr(0, 2) && c1 == c2)
        cout << 1;
    else
        cout << 0;

    if(a.substr(2, 1) < "D" && b.substr(2,1) < "D" && a.substr(0, 2) == b.substr(0, 2) && c1 == c2)
        cout << 1;
    else if(a.substr(2, 1) > "C" && b.substr(2,1) > "C" && a.substr(0, 2) == b.substr(0, 2) && c1 == c2)
        cout << 1;
    else
        cout << 0;

    if(c1 == c2 && a.substr(2, 1) > "C" && b.substr(2,1) > "C" && a.substr(0, 2) == b.substr(0, 2)){
        if(a.substr(2, 1) != b.substr(2, 1)){
            cout << 1;}
        else    cout << 0;
    }
    else if(c1 == c2 && a[2] < 'D' && b[2] < 'D' && a[2] + 1 == b[2] || a[2] - 1 == b[2]){
        if(a.substr(0, 2) == b.substr(0, 2) )
            cout << 1;
        else    cout << 0;
    }
    else
        cout << 0;

    return 0;
}
