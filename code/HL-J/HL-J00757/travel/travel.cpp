#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
char x,y;
int a,b,c,d;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a=1;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&a==1){
        b=1;
    }
    x=s1[2],y=s2[2];
    if((x>='D'&&y>='D')||(x<='C'&&y<='C')&&b==1){
        c=1;
    }
    if((x=='B'&&y=='C')||(x=='C'&&y=='B')||(x=='B'&&y=='A')||(x=='A'&&y=='B')||(x=='D'&&y=='F')||(x=='F'&&y=='D')&&c==1){
        d=1;
    }
    cout<<a<<b<<c<<d;
    return 0;
}
