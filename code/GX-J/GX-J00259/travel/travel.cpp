#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int x,y;
bool b1,b2,b3,b4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    b1=(c1==c2);
    b2=(b1&&s1[0]+s1[1]==s2[0]+s2[1]);
    b3=(b2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')));
    b4=(b3&&(!(s1[2]=='C'&&s2[2]=='A'))&&(!(s2[2]=='C'&&s1[2]=='A')));
    cout<<b1<<b2<<b3<<b4;
    return 0;
}
