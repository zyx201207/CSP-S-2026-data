#include<bits/stdc++.h>
using namespace std;
//#define int long long
string c1,s1,c2,s2;
int C1,C2;
int P1,P2;
char Z1,Z2;
void CC(){
    C1=(c1[0]-'0')*10+c1[1]-'0';
    C2=(c2[0]-'0')*10+c2[1]-'0';
    P1=(s1[0]-'0')*10+s1[1]-'0';
    P2=(s2[0]-'0')*10+s2[1]-'0';
    Z1=s1[2];Z2=s2[2];
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    CC();
    if(C1!=C2){
        cout << "0000";
        return 0;
    }
    if(P1!=P2){
        cout << "1000";
        return 0;
    }
    if(min(Z1,Z2)<'D' && max(Z1,Z2)>'C'){
        cout << "1100";
        return 0;
    }
    if(abs(Z1-Z2)>1){
        cout << "1110";
        return 0;
    }
    cout << 1111;
    return 0;
}
