#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    char r1=s1[2],r2=s2[2];
    bool a1=(r1>='A'&&r1<='C'),a2=(r1=='D'||r1=='F');
    bool b1=(r2>='A'&&r2<='C'),b2=(r2=='D'||r2=='F');
    if(c1==c2) cout<<1;
    else cout<<0;
    if(c1==c2&&s1[1]==s2[1]) cout<<1;
    else cout<<0;
    if(c1==c2&&s1[1]==s2[1]&&((a1&&b1)||a2&&b2)) cout<<1;
    else cout<<0;
    if(c1==c2&&((r1=='A'&&r2=='B')||(r1=='B'&&r2=='A')||(r1=='B'&&r2=='C')||(r1=='C'&&r2=='B')||(r1=='D'&&r2=='F')||(r1=='F'&&r2=='D'))) cout<<1;
    else cout<<0;
    return 0;
}
