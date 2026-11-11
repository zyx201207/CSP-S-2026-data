#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a1,a2,b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    a1=(c1[0]-'0')*10+(c1[1]-'0');
    a2=(c2[0]-'0')*10+(c2[1]-'0');
    if(a1!=a2){
        cout << "0000";
    }else{
        b1=(s1[0]-'0')*10+(s1[1]-'0');
        b2=(s2[0]-'0')*10+(s2[1]-'0');
        if(b1!=b2){
            cout << "1000";
        }else if(s1[2]<='C' && s2[2]<='C'){
            if(s1[2]=='B' || s2[2]=='B'){
                cout << "1111";
            }else{
                cout << "1110";
            }
        }else if(s1[2]>'C' && s2[2]>'C'){
            cout << "1111";
        }else{
            cout << "1100";
        }
    }

    return 0;
}
