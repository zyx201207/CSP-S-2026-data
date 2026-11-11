#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    string x,y,a,b;
    cin >> x >> y >> a >> b;
    if(x==a) cout << 1;
    else{
        cout << "0000";
        return 0;
    }
    if((y[0]==b[0])&&(y[1]==b[1])){
        cout << 1;
    }
    else {
        cout << "000";
    return 0;
    }
    if((y[2]<='C')&&(y[2]>='A')&&(b[2]>='A')&&(b[2]<='C')){
        cout << 1;
    }
    else if(((y[2]=='D')&&(b[2]=='F'))||((y[2]=='F')&&(b[2]=='D'))){
        cout << "11";
        return 0;
    }
    else{
        cout << "00";
        return 0;
    }
    if(y[2]==b[2]+1 or b[2]==y[2]+1) cout << 1;
    cout << 0;
    return 0;
}
