#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool f=1;
int x=0,y=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(b[2]=='A'||b[2]=='B'||b[2]=='C') x=1;
    if(d[2]=='A'||d[2]=='B'||d[2]=='C') y=1;
    a==c&&f?printf("1"):(printf("0"),f=0);
    b[0]==d[0]&&b[1]==d[1]&&f?printf("1"):(printf("0"),f=0);
    x==y&&f?printf("1"):(printf("0"),f=0);
    abs(b[2]-d[2])==1&&f?printf("1"):(printf("0"),f=0);
    return 0;
}
