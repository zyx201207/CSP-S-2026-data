#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3,f4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    f1=(c1==c2);
    f4=f3=f2=(f1&((s1[0]==s2[0])&&(s1[1]==s2[1])));
    char c1=s1[2],c2=s2[2];
    if(c1<='C'&&c2<='C')f3&=1;
    else if(c1>='D'&&c2>='D')f3&=1;
    else f3=0;
    if(c1=='A')f4&=(c2=='B');
    if(c1=='B')f4&=((c2=='A')|(c2=='C'));
    if(c1=='C')f4&=(c2=='B');
    if(c1=='D')f4&=(c2=='F');
    if(c1=='F')f4&=(c2=='D');
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
