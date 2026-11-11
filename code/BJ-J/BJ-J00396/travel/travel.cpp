#include<bits/stdc++.h>
using namespace std;
string box1,sit1,box2,sit2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> box1 >> sit1 >> box2 >> sit2;
    if(box1 == box2){
        cout << "1";
        if(sit1[0] == sit2[0] && sit1[1] == sit2[1]){
            cout << "1";
            bool side = 0,side2 = 0;
            if(sit1[2] == 'D' || sit1[2] == 'F') side = 1;
            if(sit2[2] == 'D' || sit2[2] == 'F') side2 = 1;
            if(side == side2){
                cout << "1";
                if(abs(sit1[2] - sit2[2]) == 1 && side == 0) cout << "1";
                else if(abs(sit1[2] - sit2[2]) == 2 && side == 1) cout << "1";
                else cout << "0";
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
}
