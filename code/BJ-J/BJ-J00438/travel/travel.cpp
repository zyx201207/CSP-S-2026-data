#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string c3,c4,s1,s2,num1,num2;
    cin>>c1>>c3>>c2>>c4;
    if(c1==c2) cout<<1;
    else cout<<0;
    if(c3[0]==c4[0] && c3[1]==c4[1] && c1==c2) cout<<1;
    else cout<<0;
    int a=c3[2],b=c4[2];
    if((c3[0]==c4[0] && c3[1]==c4[1] && (a<=67 && b<=67) || (a>=68 && b>=68)) && c1==c2) cout<<1;
    else cout<<0;
    if(c3[0]==c4[0] && c3[1]==c4[1] && a<=67 && b<=67 && (a-b==1 || b-a==1)) cout<<1;
    else if(c3[0]==c4[0] && c3[1]==c4[1] && a>=68 && b>=68) cout<<1;
    else cout<<0;
    return 0;
}
