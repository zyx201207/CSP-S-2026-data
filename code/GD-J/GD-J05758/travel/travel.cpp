#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    char c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2) cout<<'1';
    else cout<<'0';
    int y,t;
    y=s1/10;
    t=s2/10;
    if(y==t+10) cout<<'1';
    else cout<<'0';
    char(y=s1%10);
    char(t=s2%10);
    if(y=='A'||y=='B'||y=='C'&&t=='A'||t=='B'||t=='C') cout<<'1';
    else if(y=='D'||y=='F'&&t=='D'||t=='F') cout<<'1';
    else cout<<'0';
    if(int(y)==int(t)+10||int(y)==int(t)-10) cout<<'1';
    else cout<<'0';
    return 0;
}
