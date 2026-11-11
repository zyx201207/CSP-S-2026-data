#include<bits/stdc++.h>
using namespace std;
char a[1000],b[1000],c[1000],d[1000];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long n;
    cin>>a>>b>>c>>d;
    //cout<<a<<endl<<b<<endl<<c<<endl<<d;
    if(strcmp(a,c)==0)
    {
        cout<<"1";
    if(b[0]==d[0]&&b[1]==d[1])
    {
        cout<<"1";
        if(b[2]=='A'||b[2]=='B'||b[2]=='C')
            {
                if(d[2]=='D'||d[2]=='F')cout<<"00";
            else if(d[2]+2==b[2]||d[2]-2==b[2])cout<<"10";
            else cout<<"11";
            }
        else if(d[2]=='A'||d[2]=='B'||d[2]=='C')cout<<"00";
        else cout<<"11";
    }
    else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
