#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
    cin>>a>>b>>c>>d;
    freopen("travel.in","r"stdin);
    freopen("travel.out","w"stdout);
    //if(a[1]==c[1])cout <<"11";
    //else if(a[1])
    cout <<(a[1]==c[1]&&a[0]==c[0]);
    cout <<(a[1]==c[1]&&a[0]==c[0]&&b[1]==d[1]&&a[0]==c[0]);
    cout <<(a[1]==c[1]&&a[0]==c[0]&&b[1]==d[1]&&a[0]==c[0]&&b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D');
    cout <<(b[2]==d[2]-1||b[2]-1==d[2]);
    return 0;
}
