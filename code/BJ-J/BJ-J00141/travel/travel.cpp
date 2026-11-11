#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;   cin >> c1 >> s1 >> c2 >> s2;
    if(c1[0]!=c2[0]||c1[1]!=c2[1]) {
        cout << "0000";
    }
    else{
        cout << '1';
        if(s1[0]!=s2[0]||s1[1]!=s2[1]){
            cout << "000";
        }
        else{
            cout << '1';
            if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'){
                cout << '1';
                if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
                    cout << '1';
                }
                else cout << '0';
            }
            else{
                cout << "00";
            }
        }
    }

    return 0;
}
