#include <bits/stdc++.h>
using namespace std;

//05 01D 05 01E

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    int a, x; string b, y; cin >> a >> b >> x >> y;

    if(b[2] == 'F'){
        b[2] = 'E';
    }
    if(y[2] == 'F'){
        y[2] = 'E';
        //cout << y[2] << "\n";
    }

    //cout << a << " " << b << " " << x << " " << y << " " << (y[2] == 'F') << "\n";

    int bn = (b[0] - '0') * 10 + (b[1] - '0'), yn = (y[0] - '0') * 10 + (y[1] - '0');

    if(a != x){
        cout << "0000\n";
        return 0;
    }

    cout << (int)(a == x);
    cout << (int)(bn == yn);
    bool f = 0;
    if(('D' <= b[2] and b[2] <= 'E') and ('D' <= y[2] and y[2] <= 'E')) f = 1;
    if(('A' <= b[2] and b[2] <= 'C') and ('A' <= y[2] and y[2] <= 'C')) f = 1;
    if(!(b[0] == y[0] and b[1] == y[1])) f = 0;

    cout << (int)(f);

    if((bn + 1) == yn or (bn - 1) == yn){
        //cout << (int)((b[2] + 1) == y[2] or (b[2] - 1) == y[2]) << "\n";
        cout << (int)(b[2] == y[2]) << "\n";
    }
    else if(bn == yn){
        cout << (int)(((b[2] + 1) == y[2] or (b[2] - 1) == y[2]) and !((b[2] == 'D' and y[2] == 'C') or (b[2] == 'C' and y[2] == 'D'))) << "\n";
    }
    else{
        cout << "0\n";
    }
    return 0;
}
