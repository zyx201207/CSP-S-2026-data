#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    char s1,s11,s12,s2,s21,s22;
    cin>>c1>>s1>>s11>>s12>>c2>>s2>>s21>>s22;
    if(c1!=c2){cout<<"0000";return 0;}
    else if(s1!=s2||s11!=s21){cout<<"1000";return 0;}
    else if((s12=="A"||s12=="B"||s12=="C")&&(s22=="C"||s22=="D")||(s22=="A"||s22=="B"||s22=="C")&&(s12=="C"||s12=="D")){cout<<"1100";return 0;}
    else if((s12=="A"&&s22=="C")||(s22=="A"&&s12=="C")){cout<<"1110";return 0;}
    else cout<<"1111";
    return 0;
}