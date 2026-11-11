#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string train1,train2;
    string sit1,sit2;
    cin >> train1 >> sit1 >> train2 >> sit2;
    if(train1 == train2){
        cout << 1;
        if(sit1[0]==sit2[0]&&sit1[1]==sit2[1]){
            cout << 1;
            if(sit1[2]<='C'&&sit2[2]<='C'){
                cout << 1;
                if(sit1[2]==(sit2[2]+1)||(sit1[2]+1)==sit2[2]){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }else if(sit1[2]<='F'&&sit1[2]>'C'&&sit2[2]<'C'&&sit2[2]<='F'){
                cout << "11";
            }else{
                cout << "00";
            }
        }else{
            cout << "000";
        }
    }else{
        cout << "0000";
    }
    return 0;
}
