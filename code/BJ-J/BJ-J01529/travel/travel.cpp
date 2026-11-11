#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a1,a2;
int f(char x){
    if(x=='A')return 1;
    if(x=='B')return 2;
    if(x=='C')return 3;
    if(x=='D')return 20;
    if(x=='F')return 21;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if((s1[0]==s2[0])and(s1[1]==s2[1]))cout<<1;
    else{
        cout<<0<<0<<0;
        return 0;
    }
    a1=s1[2];
    a2=s2[2];
    long long temp1=f(a1)-f(a2),temp2=f(a2)-f(a1);
    if((temp1<=2)and(temp2<=2))cout<<1;
    else{
        cout<<0<<0;
        return 0;
    }
    if((temp1<=1)and(temp2<=1)){
        cout<<1;
        return 0;
    }
    else{
        cout<<0;
        return 0;
    }
    return 0;
}