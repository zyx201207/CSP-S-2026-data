#include<bits/stdc++.h>
using namespace std;

string ra, rb, xa, xb;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> ra >> rb >> xa >> xb;

    if(ra != xa){
        cout << "0000";
        return 0;
    }

    string rrow = string(1, rb[0]) + rb[1],
           xrow = string(1, xb[0]) + xb[1];
    if(rrow != xrow){
        cout << "1000";
        return 0;
    }

    cout << "11";
    char rs = rb[2], xs = xb[2];
    if(rs > xs) swap(rs, xs);
    if(xs == 'F') xs = 'E';

    if(rs <= 'C' && xs >= 'D'){
        cout << "00";
        return 0;
    }
    cout << "1";
    if(rs + 1 != xs) cout << "0";
    else cout << "1";

    return 0;
}
