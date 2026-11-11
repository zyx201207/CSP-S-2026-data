#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1;
    string s2;
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;
    int a=0,b=0,c=0,d=0;
    if(c1==c2){
        a=1;
    }
    if(s1[0]==s2[0] && s1[1]==s2[1]){
        b=1;
        if((s1[2]=='D' && s2[2]=='F')||(s1[2]=='F' && s2[2]=='D')){
            c=1;
            d=1;
        }
        else if((s1[2]=='A' && s2[2]=='B')||(s1[2]=='B' && s2[2]=='A')){
            c=1;
            d=1;
        }
        else if((s1[2]=='C' && s2[2]=='B')||(s1[2]=='B' && s2[2]=='C')){
            c=1;
            d=1;
        }
        else if((s1[2]=='A' && s2[2]=='C')||(s1[2]=='C' && s2[2]=='A')){
            c=1;
            d=0;
        }
    }
    cout<<a<<b<<c<<d;
    return 0;
}
