#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x, y;
    string a, b;
    cin >> x >> a >> y >> b;
    if (x == y) cout << 1;
    else {
        cout << "0000";
        return ;
    }

    if (a == b){
        cout << "000";
        return ;
    }

    if(a[0] == b[0] && a[1] == b[1]){
        cout << 1;
    }else {
        cout << "000";
        return ;
    }

    if(a[2] == 'D'){
        if (b[2] == 'F'){
            cout << 11;
            return ;
        }
        else {
            cout << "00";
            return ;
        }
    }else if(a[2] == 'F'){
        if (b[2] == 'D'){
            cout << 11;
            return ;
        }
        else {
            cout << "00";
            return ;
        }
    }else if(a[2] == 'A' || a[2] == 'B' || a[2] == 'C'){
        if (b[2] == 'A' || b[2] == 'B' || b[2] == 'C') cout << 1;
        else {
            cout << "00";
            return ;
        }
    }

    if (a[2] == 'A'){
        if (b[2] == 'B'){
            cout << 1;
            return ;
        }else{
            cout << 0;
            return ;
        }
    }
    if(a[2] == 'B'){
        cout << 1;
        return ;
    }if(a[2] == 'C'){
        if (b[2] == 'B'){
            cout << 1;
            return ;
        }else{
            cout << 0;
            return ;
        }
    }
}

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    solve();
}
