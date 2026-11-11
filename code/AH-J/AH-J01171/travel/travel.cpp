#include<bits/stdc++.h>
using namespace std;
long long int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==1||c1==16)cout<<"0000";
    else{
        if(c1==c2)cout<<'1';
           else cout<<"0";
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])cout<<"1";
       else cout<<"0";
       if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='A'&&s2[2]=='B'||s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='B'&&s2[2]=='A'||s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='B'&&s2[2]=='C'||s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='C'&&s2[2]=='B'||s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='D'&&s2[2]=='F'||s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='F'&&s2[2]=='D')cout<<"11";
       else if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='A'&&s2[2]=='C'||s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='C'&&s2[2]=='A')cout<<"10";
       else cout<<"00";
    }
    return 0;
}
