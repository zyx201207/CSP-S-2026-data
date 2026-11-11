#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    bool e=false,f=false,g=false,h=false;
    if(a==c) e=true;
    if(e==true&&(b[0]==d[0])&&(b[1]==d[1])) f=true;
    bool q=false;
    if(('A'<=b[2]<='C'&&'A'<=d[2]<='C')||('D'<=b[2]<='F'&&'D'<=d[2]<='F')) q=true;
    if(e&&f&&q) g=true;
    if(((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))&&e&&f&&g) h=true;
    if(e==true) cout<<1;
    else cout<<0;
    if(f==true) cout<<1;
    else cout<<0;
    if(g==true) cout<<1;
    else cout<<0;
    if(h==true) cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}