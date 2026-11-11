#include <bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> b >> c >> d;
    b[2] = b[2] - 'A' + 1;
    d[2] = d[2] - 'A' + 1;
    if(b[2] == 6) b[2] --;
    if(d[2] == 6) d[2] --;
    if(a == c)cout << 1;
    else return cout << "0000",0;
    if(b[0] == d[0] and b[1] == d[1]) cout << 1;
    else return cout << "000",0;
    if(((b[2] == 1 or b[2] == 2 or b[2] == 3) and (d[2] == 1 or d[2] == 2 or d[2] == 3)) or ((b[2] == 4 or b[2] == 5) and (d[2] == 4 or  d[2] == 5))) cout << 1;
    else return cout << "00",0;
    if(abs(b[2] - d[2]) == 1) cout << 1;
    else cout <<0;
    return 0;
}
/*
gugugaga
*/
