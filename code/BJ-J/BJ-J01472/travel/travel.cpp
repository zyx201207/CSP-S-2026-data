#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
    }else
        cout<<0;
    char a=s1[2],b=s2[2];
    if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C') || (a=='D'||a=='F')&&(b=='D'||b=='F'))
        cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(abs(a-b)==1 || min(a,b)=='D'&&max(a,b)=='F')
        cout<<1;
    else
        cout<<0;
}
