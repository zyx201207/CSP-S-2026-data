#include <bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
string a,n,m;
char d,x;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1!=c3)  a+='0';
    else a+='1';
    for(int i=0;i<3;i++)
    {
        d=c2[2];
        x=c4[2];
    }
    n=c2.substr(0,2);
    m=c4.substr(0,2);
    if(n==m&&c1==c2)
    {
        a+='1';

    }
    else a+='0';
    if((d>='A')&&(d<='C')&&(x>='A')&&(x<='C'))
    {
        if(n==m&&c1==c3)  a+='1';

    }
    else if((d>='D')&&(d<='F')&&(x>='D')&&(x<='F'))
    {
        if(n==m&&c1==c3)   a+='1';
    }
    else a+='0';
    if(d=='D'&&x=='C'||d=='C'&&x=='D')
    {
        a+='0';
        cout <<a;
    }
    else if((d-'0'+1)==(x-'0')||(d-'0'-1)==(x-'0'))
    {
        if(n==m&&c1==c3) a+='1';
    }
    else a+='0';
    cout <<a;
    return 0;
}
