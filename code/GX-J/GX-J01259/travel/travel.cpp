#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int m=0,n=0;
    string s1,s2,c1,c2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0] && s1[1]==s2[1])cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if(s1[2]=='A' or s1[2]=='B' or s1[2]=='C')m=1;
    else m=2;
    if(s2[2]=='A' or s2[2]=='B' or s2[2]=='C')n=1;
    else n=2;
    if(m==n)cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
    if(n==2 && m==2 or s1[2]+1 ==s2[2] or s1[2]-1 ==s2[2])cout<<"1";
    else cout<<"0";
    return 0;
}
