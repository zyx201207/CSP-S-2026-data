#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == c){
        cout << "1";
    }else{
        cout << "0000";
        return 0;
    }
    string e = b.substr(0, 2);
    string f = b.substr(2, 1);
    string g = d.substr(0, 2);
    string h = d.substr(2, 1);

    if(e == g){
        cout << "1";
    }else{
        cout << "000";
        return 0;
    }

    bool flag = false, flagg = false;
    if((f[0] == 'A' || f[0] == 'B' || f[0] == 'C') && (h[0] == 'A' || h[0] == 'B' || h[0] == 'C')){
        flag = true;
    }
    if((f[0] == 'D' || f[0] == 'F') && (h[0] == 'D' || h[0] == 'F')){
        flagg = true;
    }

    if((e == g) && (flag == true || flagg == true)){
        cout << "1";
    }else{
        cout << "00";
        return 0;
    }

    bool ok = false;
    if(flag = true){
        if((f[0] == 'A' && h[0] == 'B') || (f[0] == 'B' && h[0] == 'A') || (f[0] == 'B' && h[0] == 'C') || (f[0] == 'C' && h[0] == 'B')){
            ok = true;
        }

    }

    if(flagg = true){
        if((f[0] == 'D' && h[0] == 'F') || (f[0] == 'F' && h[0] == 'D')){
            ok = true;
        }
    }

    if(ok == true){
        cout << "1";
    }else{
        cout << "0";
        return 0;
    }

    return 0;
}
