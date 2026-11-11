#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    for(int i=1;i<=2;i++){
        cin >> c1 >> s1 >> c1 >> s1;
    }
    if(c1!=1 && c1!=16 && c1==c2) cout << "1";
    else{
        cout << "000";
        return 0;
    }
    for(int i=1;i<=2;i++){
        if(s1[1]==s2[1] && s1[2]==s2[2]) cout << "1";
        else{
            cout << "00";
            return 0;
        }
        if(s1[2]>="A" && s1[2]<="C" && s2[2]>="A" && s2[2]<="C"){
            if(abs(s1[3]-s2[3]==1)) cout << "1";
            else{
                cout <<"0";
                return 0;
            }
        }
        else if(s1[3]>="D" && s1[3]<="F" && s2[3]>="D" && s2[3]<="F"){
            if(abs(s1[3]-s2[3]==1)) cout << "1";
            else{
                cout <<"0";
                return 0;
            }
        }
        else if(s1[2]=="C"&&s2[2]=="C"&&s1[2]=="D"&&s2[2]=="D"){

        }
    }
    return 0;
}
