#include <bits/stdc++.h>
using namespace std;

int x,y;

int pai(char a,char b){
    if(a == 'A'|| a == 'B' || a == 'C'){
        x = 0;
    }
    else {
        x = 1;
    }
    if(b == 'A'|| b == 'B' || b == 'C'){
        y = 0;
    }
    else {
        y = 1;
    }
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;

    cin >> c1 >> s1 >> c2 >> s2;

    pai(s1[2],s2[2]);

    if(c1 == c2)  {
        cout << 1;
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            cout << 1;
            if(x == y){
                cout << 1;
                if(s1[2]-1 ==s2[2] || s1[2]+1 == s2[2]){
                    cout << 1;
                }
                else {
                    cout << 0;
                }
            }
            else{
                cout << "00";
            }
        }
        else {
            cout << "000";
        }

}
    else {
        cout << "0000";
    }
    return 0;
}

