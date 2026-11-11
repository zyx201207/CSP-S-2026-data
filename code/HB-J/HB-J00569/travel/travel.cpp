#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    string s1,s2;
    cin>>c1>>s1;
    cin>>c2>>s2;
    string s11=s1.substr(0,2);
    string s21=s2.substr(0,2);
    char s12=s1[2];
    char s22=s2[2];
    if (c1==c2)printf("1");
    else{printf("0000");return 0;}
    if (s11==s21)printf("1");
    else{printf("000");return 0;}
    if (s12<'D' && s22<'D')printf("1");
    else if (s12>='D' && s22>='D')printf("1");
    else{printf("00");return 0;}
    if (s12<'D' && s22<'D' && abs(s12-s22)==1)printf("1");
    else if (s12>='D' && s22>='D')printf("1");
    else{printf("0");return 0;}
    return 0;
}
//Desktop/HB-J00569/travel/travel.cpp >Hello

