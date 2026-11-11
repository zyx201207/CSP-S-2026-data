#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string carry1, seat1, carry2, seat2;
    cin >> carry1 >> seat1 >> carry2 >> seat2;
    if(carry1==carry2){
        cout << "1";
        if(seat1[0]==seat2[0]&&seat1[1]==seat2[1]){
            cout << "1";
            if(seat1[2]<='C'&&seat2[2]<='C'||seat1[2]>='D'&&seat2[2]>='D'){
                cout <<"1";
                if(seat1[2]==seat2[2]-1||seat1[2]==seat2[2]+1){
                    cout << "1";
                }
                else cout << "0";
            }
            else cout <<"00";
        }
        else cout <<"000";
    }
    else{
        cout << "0000";
    }




    fclose(stdin);
    fclose(stdout);
    return 0;
}
