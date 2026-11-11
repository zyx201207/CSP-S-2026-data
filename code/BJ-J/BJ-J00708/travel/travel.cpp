#include<bits/stdc++.h>
using namespace std;
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1;
string s1;
string c2;
string s2;
int f1=0,f2=0,f3=0,f4=0;
int main(){
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;
    if(c1==c2){
        f1=1;
    }
    if(c1==c2){
        if(s1[0]==s2[0]&&s1[1]==s1[1]){
            f2=1;
        }
    }
    if(f2==1){
        if(s1[2]=='D'&&s2[2]=='F'){
            f3=1;
            f4=1;
        }
        if(s2[2]=='D'&&s1[2]=='F'){
            f3=1;
            f4=1;
        }
        if(s1[2]!='D'&&s1[2]!='F'&&s2[2]!='F'&&s2[2]!='D'){
            f3=1;
        }
    }
    if(f4!=1&&f3==1){
        if(s1[2]=='A'&&s2[2]=='B'){
            f4=1;
        }
        if(s1[2]=='B'&&s2[2]=='A'){
            f4=1;
        }
        if(s1[2]=='B'&&s2[2]=='C'){
            f4=1;
        }
        if(s1[2]=='C'&&s2[2]=='B'){
            f4=1;
        }
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
