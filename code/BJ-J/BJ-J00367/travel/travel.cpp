#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int f1=0,f2=0,f3=0,f4=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        f1=1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            f2=1;
            if(s1[2]=='F'&&s2[2]=='D') f3=1;
            else if(s1[2]=='D'&&s2[2]=='F') f3=1;
            else if(s1[2]=='C'&&(s2[2]=='B'||s2[2]=='A')) f3=1;
            else if(s1[2]=='B'&&(s2[2]=='C'||s2[2]=='A')) f3=1;
            else if(s1[2]=='A'&&(s2[2]=='C'||s2[2]=='B')) f3=1;
            if(f3==1){
                if(s1[2]=='F'&&s2[2]=='D') f4=1;
                else if(s1[2]=='D'&&s2[2]=='F') f4=1;
                else if(s1[2]=='C'&&s2[2]=='B') f4=1;
                else if(s1[2]=='B'&&(s2[2]=='C'||s2[2]=='A')) f4=1;
                else if(s1[2]=='A'&&s2[2]=='B') f4=1;
            }
        }
    }
    if(f1==1) cout<<'1';
    else cout<<'0';
    if(f2==1) cout<<'1';
    else cout<<'0';
    if(f3==1) cout<<'1';
    else cout<<'0';
    if(f4==1) cout<<'1';
    else cout<<'0';
    return 0;
}