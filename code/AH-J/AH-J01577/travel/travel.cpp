#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
char s[10];
int main(){
    //freopen("travel.in","r",stdin);
   // freopen("travel.out","w",stdout);
    int a1,a2;
    string b1,b2;
    cin>>a1>>b1>>a2>>b2;
    string s;
    if(a1==a2){

    }
    else {
            cout<<"0000";
            return 0;
    }
    int sum1=0,sum2=0;
    for(int i=0;i<=1;i++){
        sum1*=10;
        sum2*=10;
        sum1+=b1[i]-'0';
        sum2+=b2[i]-'0';
    }
    if(sum1==sum2){

    }
    else {
        cout<<1000;
        return 0;
    }
    if(b1[2]=='D'&&b2[2]=='F'||b1[2]=='F'&&b2[2]=='D'||b1[2]=='A'&&(b2[2]=='B'||b2[2]=='C')||b1[2]=='B'&&(b2[2]=='A'||b2[2]=='C')||b1[2]=='C'&&(b2[2]=='B'||b2[2]=='A')||b2[2]=='A'&&(b1[2]=='B'||b1[2]=='C')||b2[2]=='B'&&(b1[2]=='A'||b1[2]=='C')||b2[2]=='C'&&(b1[2]=='B'||b1[2]=='A')){
        s[1]=1;
    }
    else {
        cout<<1100;
        return 0;
    }
    if(b1[2]=='D'&&b2[2]=='F'||b1[2]=='F'&&b2[2]=='D'||b1[2]=='A'&&b2[2]=='B'||b1[2]=='B'&&(b2[2]=='A'||b2[2]=='C')||b1[2]=='C'&&b2[2]=='B'||b2[2]=='A'&&b1[2]=='B'||b2[2]=='B'&&(b1[2]=='A'||b1[2]=='C')||b2[2]=='C'&&b1[2]=='B'){

    }
    else {
        cout<<1110;
        return 0;
    }
    cout<<1111;
    return 0;
}
