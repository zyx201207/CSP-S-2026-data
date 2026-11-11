#include <bits/stdc++.h>
using namespace std;
char c1,c2,s1,s2;
int a,b,c,d;
bool check(){
    if(s1>'C'&&s2>'C') return 1;
    if(s1<='C'&&s2<='C') return 1;
    return 0;
}
bool check2(){
    if((a!=c)||(b!=d)) return 0;
    if(s1>'C'&&s2>'C') return 1;
    if(s1<='C'&&s2<='C'){
        if((s1=='A'&&s2=='C')||(s1=='C'&&s2=='A'))  return 0;
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2;
    a=(c1-'0')*10+(c2-'0');
    cin>>c1>>c2;
    b=(c1-'0')*10+(c2-'0');
    cin>>s1>>c1>>c2;
    c=(c1-'0')*10+(c2-'0');
    cin>>c1>>c2;
    d=(c1-'0')*10+(c2-'0');
    cin>>s2;

    cout<<(a==c)<<((a==c)&&(b==d))<<((a==c)&&(b==d)&&check())<<check2();

    return 0;
}
