#include <bits/stdc++.h>
using namespace std;
#define int long long
int k1,k2,x1,x2;
string c1,s1,c2,s2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1==c2){
        cout << 1;
    }
    else {
        cout << "0000";
        return 0;
    }
    if (s1[0]==s2[0]&&s1[1]==s2[1]){
        cout << 1;
    }
    else {
        cout << "000";
        return 0;
    }
    if (s1[2]<='C') k1=0;
    else k1=1;
    if (s2[2]<='C') k2=0;
    else k2=1;
    if (k1==k2){
        cout << 1;
    }
    else {
        cout << "00";
        return 0;
    }
    x1 = s1[2]-'A'; x2 = s2[2]-'A';
    if (k1==0&&abs(x1-x2)==1) cout << 1;
    else if (k1==1) cout << 1;
    else cout << 0;
    return 0;
}