#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d,s;
    cin>>a>>b>>c>>d;
    if(a==c)s+="1";
    else s+="0";
    if(a==c&&b[0]==d[0]&&b[1]==d[1])s+="1";
    else s+="0";
    if(a==c&&b[0]==d[0]&&b[1]==d[1]&&(b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C'))s+="1";
    else s+="0";
    if(a==c&&b[0]==d[0]&&b[1]==d[1]&&(b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C')&&(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'))s+="1";
    else s+="0";
    cout<<s;
    return 0;
}
