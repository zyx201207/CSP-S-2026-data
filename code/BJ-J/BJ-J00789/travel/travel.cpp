#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,e,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","r",stdout);
    cin>>a>>b>>c>>d;
    cout<<(a==c);
    e=b[0]+b[1];
    f=d[0]+d[1];
    cout<<(e==f&&a==c);
    char a1,b1;
    a1=b[2];
    b1=d[2];
    cout<<(((a1>='A'&&a1<='C'&&b1>='A'&&b1<='C')||(a1>='D'&&a1<='F'&&b1>='D'&&b1<='F'))&&e==f&&a==c);
    cout<<((((a1>='A'&&a1<='C'&&b1>='A'&&b1<='C')||(a1>='D'&&a1<='F'&&b1>='D'&&b1<='F'))&&(a1==b1+1||b1==a1+1))&&e==f&&a==c);
    return 0;
}
