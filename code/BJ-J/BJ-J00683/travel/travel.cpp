#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,num1,num2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    num1 = num1 + s1[0];
    num1 = num1 + s1[1];
    num2 = num2 + s2[0];
    num2 = num2 + s2[1];
    if(c1 == c2) cout <<1;
    else cout <<0;
    if(c1 == c2 && num1 == num2) cout <<1;
    else cout <<0;
    if(c1 == c2 && num1 == num2){
        if(s1[2] <= 'C' && s2[2] >= 'D' || s1[2] >= 'D' && s2[2] <= 'C'){
            cout << "00";
        }else{
            cout <<1;
            if(s1[2] + 1 == s2[2] || s2[2]+1 == s1[2]) cout << 1;
            else cout <<0;
        }
    }else cout << "00";
    return 0;
}
