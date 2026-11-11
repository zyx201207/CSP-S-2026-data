#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel5.in","r",stdin);
    freopen("travel.out","w",stdout);
    string n,m,a,b;
    int h  = 0,r = 0;
    cin >> n >> m >> a >> b;
    if(n == a){
        h = 1;
        cout << '1';
    }
    else{
        cout << '0';
    }
    if(m[1] == b[1] and h == 1){
        cout <<'1';
    }
    else{
        cout <<'0';
    }
    if(m[1] == b[1] and h == 1 and ((m[2]<='C' and b[2]<='C') or (m[2]>'C' and b[2]>'C'))){
       cout <<'1';
       r = 1;
    }
    else{
        cout <<'0';
    }
    if(r == 1){
        if(b[2] > m[2]){
            if(b[2]-m[2] == 1){
                cout << '1';
            }
            else{
                cout << '0';
            }
        }
        else{
            if(m[2]-b[2] == 1){
                cout << '1';
            }
            else{
                cout << '0';
            }
        }
    }
    else{
        cout <<'0';
    }
}
