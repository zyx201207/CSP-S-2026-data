#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    bool flag = 0;
    cin >>a1>>a2>>b1>>b2;
    if(a1 == b1) cout <<1;else {cout <<0;flag = 1;}
    int num1,num2;
    num1 = int(a2[0]-'0')*10+a2[1];
    num2 = int(b2[0]-'0')*10+b2[1];
    if(flag) cout <<0;
    else if(num1 == num2) cout <<1;else {flag = 1;cout <<0;}

    if(flag) cout <<0;
    else if(int(a2[2])<='C' && int(a2[2])>='A' && int(b2[2])<='C' && int(b2[2])>='A') cout <<1;
    else if(int(a2[2])<='F' && int(a2[2])>='D' && int(b2[2])<='F' && int(a2[2])>='D') cout <<1;
    else {cout <<0;flag = 1;}

    if(!flag && (a2[2]+1 == b2[2] || a2[2]-1 == b2[2])) cout <<1;
    else cout <<0;
    return 0;
}
