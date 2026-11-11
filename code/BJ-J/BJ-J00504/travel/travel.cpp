#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
bool f1,f2,f3,ff3,f4,ff4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    if(a==b){
        cout<<1;
        f1=1;
    }else{
        cout<<0;
    }
    int h1=10*(c[0]-'0')+(c[1]-'0');
    int h2=10*(d[0]-'0')+(d[1]-'0');
    if(h1==h2&&f1){
        cout<<1;
        f2=1;
    }else{
        cout<<0;
    }
    if((c[2]=='A'&&d[2]=='B')||(c[2]=='A'&&d[2]=='C')||(c[2]=='B'&&d[2]=='C')||(c[2]=='D'&&d[2]=='F')){
        ff3=1;
    }
    char cc=d[2];
    char dd=c[2];
    if(((cc=='A'&&dd=='B')||(cc=='A'&&dd=='C')||(cc=='B'&&dd=='C')||(cc=='D'&&dd=='F')||(ff3==1))&&f1==1&&f2==1){
        f3=1;
        cout<<1;
    }else{
        cout<<0;
    }
    if(((c[2]=='A'&&d[2]=='B')||(c[2]=='B'&&d[2]=='C')||(c[2]=='D'&&d[2]=='F'))&&f3==1){
        ff4=1;
    }
    if(((cc=='A'&&dd=='B')||(cc=='B'&&dd=='C')||(cc=='D'&&dd=='F')||(ff4==1))&&f3==1){
        f4=1;
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}