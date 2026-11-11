#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i = a;i <= b;i++)
using namespace std;
string c1,s1,c2,s2;
int main(){
    //Gino Jiu 99
    //nothing could better when i with you,when i with you~
    //X X XXX
    //X X XXX
    //XX X XXXX
    //XX X XXXX
    //hyw 14 14.9>15(
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << "1";
    }else{
        cout << "0000";
        return 0;
    }
    if(s1[0] == s2[0] && s1[1] == s2[1]){
        cout << "1";
    }else{
        cout << "000";
        return 0;
    }
    if(
       ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') &&
       (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) ||
       ((s1[2] == 'D' || s1[2] == 'F' ) &&
       (s2[2] == 'D' || s2[2] == 'F' ))
       ){
        cout << "1";
    }else{
        cout << "00";
        return 0;
    }
    if(abs(int(s1[2]) - int(s2[2])) == 1 ||
       (int(s1[2]-'A'+1) * int(s2[2]-'A'+1)) == 24){
        cout << "1";
    }else{
        cout << "0";
    }
    return 0;
}
