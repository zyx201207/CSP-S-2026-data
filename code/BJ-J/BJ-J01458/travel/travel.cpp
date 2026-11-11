#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f=true;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
        cout<<1;
    else{
        cout<<0;
        f=false;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&f)
        cout<<1;
    else{
        cout<<0;
        f=false;
    }
    if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&f||s1[2]=='D'&&s2[2]=='F'&&f||s1[2]=='F'&&s2[2]=='D'&&f)
        cout<<1;
    else{
        cout<<0;
        f=false;
    }
    if(s1[2]=='A'&&s2[2]=='B'&&f||s1[2]=='B'&&s2[2]=='A'&&f||s1[2]=='C'&&s2[2]=='B'&&f||s1[2]=='B'&&s2[2]=='C'&&f||s1[2]=='D'&&s2[2]=='F'&&f||s1[2]=='F'&&s2[2]=='D'&&f)
        cout<<1;
    else{
        cout<<0;
        f=false;
    }
    return 0;
}
