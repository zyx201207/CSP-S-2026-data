#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a1 >> a2 >> b1 >> b2;
    if(a1!=b1){
        cout << "0000";
        return 0;
    }
    cout << 1;
    if(a2[0]!=b2[0] or a2[1]!=b2[1]){
        cout << "000";
        return 0;
    }
    cout << 1;
    if(a2[2]<'D' and b2[2]>='D' or a2[2]>'C' and b2[2]<='C'){
        cout << "00";
        return 0;
    }
    cout << 1;
    if(a2[2]+1==b2[2] or a2[2]-1==b2[2])
        cout << 1;
    else
        cout << 0;
    return 0;
}
