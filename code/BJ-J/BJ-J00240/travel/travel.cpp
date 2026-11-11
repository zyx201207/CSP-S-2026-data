#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    char z1=s1[2],z2=s2[2];
    int v1,v2;
    v1=(s1[0]-'0')*10 + (s1[1]-'0');
    v2=(s2[0]-'0')*10 + (s2[1]-'0');
    cout<<(c1==c2) ? 1 : 0;
    cout<<(c1==c2 && v1==v2) ? 1 : 0;
    if(c1==c2 && v1==v2){
        if(z1>='A'&&z1<='C' && z2>='A'&&z2<='C') cout<<1;
        else if((z1=='D'||z1=='F') && (z2=='D'||z2=='F')) cout<<1;
        else cout<<0;
    }else cout<<0;
    if(c1==c2 && v1==v2){
        if(z1=='A'&&z2=='B') cout<<1;
        else if(z1=='B'&&z2=='C') cout<<1;
        else if(z1=='D'&&z2=='F') cout<<1;

        else if(z1=='F'&&z2=='D') cout<<1;
        else if(z1=='C'&&z2=='B') cout<<1;
        else if(z1=='B'&&z2=='A') cout<<1;

        else cout<<0;
    }else cout<<0;
    return 0;
}
