#include<bits/stdc++.h>
using namespace std;
int a,c,e,f,g,h,i,j;
string b,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    e=(b[0]-'0')*10+b[1]-'0';
    f=(d[0]-'0')*10+d[1]-'0';
    g=(b[2]<='C'),h=(d[2]<='C');
    if(b[2]=='D')i=5;
    else i=b[2]-'A'+1;
    if(d[2]=='D')j=5;
    else j=d[2]-'A'+1;
    cout<<(a==c)<<((a==c)&&(e==f))<<((a==c)&&(e==f)&&(g==h))<<((a==c)&&(e==f)&&(g==h)&&(abs(i-j)<=1));
    return 0;
}