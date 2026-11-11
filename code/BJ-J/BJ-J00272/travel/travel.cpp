#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main(){
    freopen('travel.in', 'r', stdin);
    freopen('travel.out', 'w', stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2){
        cout << 0;
    }else cout <<1;
    char a = s1[0];
    char b = s2[0];
    if(a != b){
        cout << 0;
    }else if( a == b){
        char a = s1[1];
        char b = s2[1];
        if(a != b){
            cout <<000;

        }else if(a == b){
            cout <<1;
            char c = s1[2];
            char d = s2[2];
            if(c == 'A' || c == 'B' || c=='C'){
                if(d =='A' || d=='B' || d=='C'){
                    cout <<1;
                }
            } else if (c=='D' || c=='E'){
                if(d=='D'||d=='E'){
                    cout <<1;
                } else cout <<0;
            }
            if(c - 'A' -(d - 'A') == 1 || d - 'A' - (c - 'A') == 1){
                cout <<1 ;

            }else cout <<0;
        }
    }
}