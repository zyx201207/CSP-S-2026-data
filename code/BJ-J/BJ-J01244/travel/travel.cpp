#include <bits/stdc++.h>
using namespace std ;
int main (){
    freopen("travel.in","r",stdin) ;
    freopen("travel.out","w",stdout) ;
    string box1 , sit1 , box2 , sit2 ;
    cin >> box1 >> sit1 >> box2 >> sit2 ;
    if (box1 == box2){
        cout << '1' ;
        int str1 = sit1[0]-'0' + sit1[1]-'0' ;//1 paishu
        int str2 = sit2[0]-'0' + sit2[1]-'0' ;//2 paishu
        int a = sit1[2] - 'A' ;
        int b = sit2[2] - 'A' ;//012 35
        bool loc1 , loc2 ;
        if (a > 2){
            loc1 = 1 ;
        }
        else{
            loc1 = 0 ;
        }
        if (b > 2){
            loc2 = 1 ;
        }
        else{
            loc2 = 0 ;
        }
        if (str1 == str2){
            cout << '1' ;
            if (loc1 == loc2){
                cout << '1' ;
                if (abs(a-b) == 1){
                    cout << '1' ;
                }
                else{
                    cout << '0' ;
                }
            }
            else{
                cout << "00" ;
            }
        }
        else{
            cout << "000" ;
        }
    }
    else{
        cout << "0000" ;
    }
    return 0 ;
}
