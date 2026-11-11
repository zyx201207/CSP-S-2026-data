#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int a=int(s1[2]-'A');
    int b=int(s2[2]-'A');
    if(c1[0]==c2[0] && c1[1]==c2[1]){
        cout << "1";
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            cout << "1";
            if((a<=2 && b<=2) || (a>=3 && b>=3)){
                cout << "1";
                if((a==b+1 || a==b-1)){
                    cout << "1";
                }
                else cout << "0";
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
