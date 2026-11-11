#include <bits/stdc++.h>
using namespace std;
bool b1,b2,b3,b4;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,n1,s2,n2;
    cin >> s1 >> n1 >> s2 >> n2;
    if(s1==s2){
        b1=true;
        if(n1[0]==n2[0]&&n1[1]==n2[1]){
            b2=true;
            if(n1[2]<=67&&n2[2]<=67||n1[2]>=68&&n2[2]>=68){
                b3=true;
                if(abs(n1[2]-n2[2])==1){
                    b4=true;
                }
            }
        }
    }
    cout << b1 << b2 << b3 << b4;
    return 0;
}
