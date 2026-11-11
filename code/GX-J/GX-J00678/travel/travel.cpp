#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int i,j=0,m=0,n=0,c1,c2;
    char s1[3],s2[3];
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else {
        cout<<"0000";
        return 0;
    }
    for(i=0;i<=1;i++){
        if(s1[i]==s2[i])m++;
    }
    if(m==2) cout<<1;
    else {
        cout<<"000";
        return 0;
    }
    if(s1[2]=='A'&&s2[2]=='B')cout<<1;
    else if(s1[2]=='B'&&s2[2]=='A')cout<<1;
    else if(s1[2]=='C'&&s2[2]=='A')cout<<1;
    else if(s1[2]=='A'&&s2[2]=='C')cout<<1;
    else if(s1[2]=='B'&&s2[2]=='C')cout<<1;
    else if(s1[2]=='C'&&s2[2]=='B')cout<<1;
    else if(s1[2]=='D'&&s2[2]=='F')cout<<1;
    else if(s1[2]=='F'&&s2[2]=='D')cout<<1;
    else {
        cout<<"00";
        return 0;
    }
    if(s1[2]=='B'&&s2[2]=='A')cout<<1;
    else if(s1[2]=='A'&&s2[2]=='B')cout<<1;
    else if(s1[2]=='B'&&s2[2]=='C')cout<<1;
    else if(s1[2]=='C'&&s2[2]=='B')cout<<1;
    else if(s1[2]=='D'&&s2[2]=='F')cout<<1;
    else if(s1[2]=='F'&&s2[2]=='D')cout<<1;
    else cout<<"0";
    return 0;
}
