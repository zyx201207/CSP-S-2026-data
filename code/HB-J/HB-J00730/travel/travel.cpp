#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,x,y;
    string s1,s2,ans="";
    char a,b;
    cin>>c1>>s1>>c2>>s2;

    a=s1[2];
    b=s2[2];
    if(a>b){
        char t=b;
        b=a;
        a=t;
    }
    x=(s1[0]-'0')*10+(s1[1]-'0');
    y=(s2[0]-'0')*10+(s2[1]-'0');
    if(c1==c2) ans+="1";
    else ans+="0";
    if(c1==c2&&x==y) ans+="1";
    else ans+="0";
    if(c1==c2&&x==y&&((a=='D'&&b=='F')||(a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='C'))) ans+="1";
    else ans+="0";
    if(c1==c2&&x==y&&((a=='D'&&b=='F')||(a=='A'&&b=='B')||(a=='B'&&b=='C'))) ans+="1";
    else ans+="0";
    cout<<ans;
    return 0;
}
