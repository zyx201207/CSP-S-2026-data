#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a1,b1,a2,b2;
char ch1,ch2;
bool f=1;
int main(){
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else{
        cout<<0;
        f=0;
    }
    ch1=s1[s1.size()-1];
    ch2=s2[s1.size()-1];
    b1=ch1;
    b2=ch2;
    a1=(s1[0]-'0')*10+s1[1]-'0';
    a2=(s2[0]-'0')*10+s2[1]-'0';
    if(f&&a1==a2&&c1==c2)cout<<1;
    else{
        cout<<0;
        f=0;
    }
    if(f&&ch1>='A'&&ch1<='C'&&ch2<='C'&&ch2>='A'||f&&ch1>='E'&&ch1<='F'&&ch2>='E'&&ch2<='F')cout<<1;
    else{
        cout<<0;
        f=0;
    }
    if(f&&abs(b1-b2)==1&&b1!='C'&&b2!='D'||f&&abs(b1-b2)==1&&b1!='D'&&b2!='C')cout<<1;
    else cout<<0;
    return 0;
}
