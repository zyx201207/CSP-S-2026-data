#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<"1";
    else cout<<"0";
    if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<"1";
    else cout<<"0";
    if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))cout<<"1";
    else cout<<"0";
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        char a=s1[2];
        char c=s2[2];
        if((a=='A'&&c=='B')||(a=='B'&&c=='C')||(a=='C'&&c=='D')||(a=='D'&&c=='F')||(c=='A'&&a=='B')||(c=='B'&&a=='C')||(c=='C'&&a=='D')||(c=='D'&&a=='F'))
            cout<<"1";
        else cout<<"0";
    }
    if(s1[2]==s2[2]){
         int n=(s1[0]-'0')*10+s1[1]-'0';
         int m=(s2[0]-'0')*10+s2[1]-'0';
         if(n-1==m||n+1==m)
         cout<<"1";
         else cout<<"0";
    }
    return 0;
}
