#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string a;
    a=s1[0]+s1[1];
    string b;
    b=s2[0]+s2[1];
    char ch1=s1[2],ch2=s2[2];
    if(ch1>ch2) swap(ch1,ch2);
    bool f1=0,f2=0,f3=0,f4=0;
    if(c1==c2){
        f1=1;
    }
    if(f1==1&&a==b){
        f2=1;
    }
    if(f1==1&&f2==1&&  ((ch1=='D'&&ch2=='F')||(ch1=='B'&&ch2=='C')||(ch1=='A'&&ch2=='B')||(ch1=='A'&&ch2=='C'))   ){
        f3=1;
    }
    if(f1==1&&f2==1&&f3==1&& ((ch1=='A'&&ch2=='B')||(ch1=='B'&&ch2=='C')||(ch1=='D'&&ch2=='F')) ){
        f4=1;
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
/*
f
d

c
b
a
*/
