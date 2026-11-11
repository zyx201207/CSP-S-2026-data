#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int c1,x1;
string c2,x2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >>c1 >> c2 >> x1 >> x2;
    if(c1 == x1){
        cout << 1;
    }else{
        cout <<"0000";
        return 0;
    }
    if(c2[0] == x2[0] && c2[1] == x2[1]){
        cout << 1;
    }else {
        cout<<"000";
        return 0;
    }
    if(c2[0] == x2[0] && c2[1] == x2[1]){
        if(c2[2] == 'C' && x2[2] == 'D' or c2[2] == 'D' && x2[2] == 'C'){
            cout<<"00";
            return 0;
        }else{
            cout<<1;
        }
    }
    if(c2[2] == x2[2] -1 or c2[2] == x2[2] +1){
            cout<<1;
    }else{
        cout<<"0";
    }
    return 0;
}
