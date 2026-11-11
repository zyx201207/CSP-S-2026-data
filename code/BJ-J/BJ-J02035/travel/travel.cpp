#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","r",stdout);
    string c1 , c2 , s1 , s2;
    bool a , b , c , d;
    a = b = c = d = 0;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1[1] == c2[1] and c1[2] == c2[2]){
        a = 1;
        if(s1[1] == s2[1] and s1[2] == s2[2]){
        b = 1;
            if(s1[3] == 'D' and s2[3] == 'F' or s1[3] == 'F' and s2[3] == 'D' or s1[3] == 'A' and s2[3] == 'B' or s1[3] == 'B' and s2[3] == 'A' or s1[3] == 'B' and s2[3] == 'C' or s1[3] == 'C' and s2[3] == 'B'){
                c = d = 1;
                cout << a << b << c << d;
                return 0;
            }else{
                if(s1[3] == 'A' and s2[3] == 'C' or s1[3] == 'A' and s2[3] == 'C'){
                    c = 1;
                    cout << a << b << c << d;
                }else{
                    cout << a << b << c << d;
                }
            }
        }else{
            cout << a << b << c << d;
            return 0;
        }
    }else{
        cout << a << b << c << d;
        return 0;
    }
    return 0;
}
