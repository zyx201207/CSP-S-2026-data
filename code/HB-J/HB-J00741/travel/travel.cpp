#include<bits/stdc++.h>
using namespace std;
char a[10],b[10],c[10],d[10];
int main()
{
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    if(a[0]==b[0]&&a[1]==b[1]) cout<<'1';
    else cout<<'0';
    if(a[0]==b[0]&&a[1]==b[1]&&c[0]==d[0]&&c[1]==d[1]) cout<<'1';
    else cout<<'0';
    if(a[0]==b[0]&&a[1]==b[1]&&c[0]==d[0]&&c[1]==d[1]&&!(c[2]=='C'&&d[2]=='D'||c[2]=='D'&&d[2]=='C')) cout<<'1';
    else cout<<'0';
    if(a[0]==b[0]&&a[1]==b[1]&&c[0]==d[0]&&c[1]==d[1]&&!(c[2]=='C'&&d[2]=='D'||c[2]=='D'&&d[2]=='C')&&max(c[2],d[2])-min(c[2],d[2])==1) cout<<'1';
    else cout<<'0';
    return 0;
}
