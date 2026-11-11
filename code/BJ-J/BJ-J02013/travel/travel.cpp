#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
string c1,s1,c2,s2;
int a1,b1,a2,b2;
signed main(){
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2){
        cout << 1;
    }else{
        cout << "0000";
        return 0;
    }
    for (int i=0;i<=1;i++){
        b1*=10;
        b2*=10;
        b1+=s1[i]-'0';
        b2+=s2[i]-'0';
    }
    if (b1==b2){
        cout << 1;
    }else{
        cout << "000";
        return 0;
    }
    if ((s1[2]=='C'||s1[2]=='B'||s1[2]=='A')&&(s2[2]=='C'||s2[2]=='B'||s2[2]=='A')){
        cout << 1;
    }else if ((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
        cout << "11";
        return 0;
    }else {
        cout << "00";
        return 0;
    }
    if ((s1[2]-1==s2[2])||(s1[2]+1==s2[2])){
        cout << 1;
    }else {
        cout << 0;
    }
    return 0;
}
