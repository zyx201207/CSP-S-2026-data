#include<bits/stdc++.h>
using namespace std;
string s1,s2;
long long a,b,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    if(a==b)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }

    if(s1[1]==s2[1]&&s1[0]==s2[0]&&f==0)cout<<1;
    else{
        cout<<"000";
        return 0;
    }

    if(((s1[2]=='A'||s1[2]=='C'||s1[2]=='B')&&(s2[2]=='A'||s2[2]=='C'||s2[2]=='B'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))&&f==0)cout<<1;
    else{
        cout<<"00";
        return 0;
    }

    if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')&&f==0)cout<<1;
    else cout<<"0";
    return 0;
}
