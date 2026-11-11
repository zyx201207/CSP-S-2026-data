#include <bits/stdc++.h>
using namespace std;
int main (){
    freopen ("travel.in", "r", stdin);
    freopen ("travel.out", "w", stdout);
    string rc, rs, xc, xs;
    cin >> rc >> rs >> xc >> xs;
    cout << (rc==xc);
    if (rc==xc){
        cout << (rs[0]==xs[0]&&rs[1]==xs[1]);
        if (rs[0]==xs[0]&&rs[1]==xs[1]){
            cout << ((rs[2]>='A'&&rs[2]<='C')&&(xs[2]>='A'&&xs[2]<='C')||(rs[2]>='D'&&rs[2]<='F')&&(xs[2]>='D'&&xs[2]<='F'));
            if ((rs[2]>='A'&&rs[2]<='C')&&(xs[2]>='A'&&xs[2]<='C'))
                cout << (abs((int)rs[2]-(int)xs[2])==1);
            else if ((rs[2]>='D'&&rs[2]<='F')&&(xs[2]>='D'&&xs[2]<='F'))
                cout << (abs((int)rs[2]-(int)xs[2])==2);
            else
                cout << "0";
        }
        else
            cout << "00";
    }
    else
        cout << "000";
    return 0;
}
