#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> b >> c >> d;
    if(a != c){
        cout << "0000";
        return 0;
    }
    cout << "1";
    for(int i = 0;i < 2;i++){
        if(b[i] != d[i]){
            cout << "000";
            return 0;
        }
    }
    cout << "1";
    char x = b[2],y = d[2];
    if('A' <= x && x <= 'C' && 'A' <= y && y <= 'C')cout << "1";
    else if(x == 'D' && y == 'F' || x == 'F' && y == 'D')cout << "1";
    else{
        cout << "00";
        return 0;
    }
    if(x == y-1 || y == x-1)cout << "1";
    else if(x == 'D' && y == 'F' || x == 'F' && y == 'D')cout << "1";
    else cout << 0;
    return 0;
}
