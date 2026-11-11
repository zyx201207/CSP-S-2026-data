#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, b, c, d;
    bool s = 0, x = 0, ch = 0, sh = 0;
    cin >> a >> b >> c >> d;
    if(a == c){
        s = 1;
        if(b[0] == d[0] && b[1] == d[1]){
            x = 1;
            if(b[2] - 'A' + 1 + 'A' == d[2] || b[2] - 'A' - 1 + 'A' == d[2]){
                if((b[2] == 'C' && d[2] == 'D') || (b[2] == 'D' && d[2] == 'C')){
                    ch = 0;
                    sh = 0;
                }
                else{
                    ch = 1;
                    sh = 1;
                }
            }
            else if(b[2] - 'A' + 2 + 'A' == d[2] || b[2] - 'A' - 2 + 'A' == d[2]){
                if((b[2] == 'D' && d[2] == 'F') || (b[2] == 'F' && d[2] == 'D')){
                    ch = 1;
                    sh = 1;
                }
                else{
                    ch = 1;
                }
            }
        }
    }
    cout << s << x << ch << sh;
    return 0;
}
