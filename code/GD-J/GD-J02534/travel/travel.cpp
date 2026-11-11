#include <bits/stdc++.h>
using namespace std;
string dr1,dr2,dx1,dx2;//r的输入1和2，x的输入1和2
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>dr1>>dr2>>dx1>>dx2;
    if(dr1==dx1)
    {
        cout<<1;
    }
    else
    {
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(dr2[0]==dx2[0]&&dr2[1]==dx2[1])
    {
        cout<<1;
    }
    else
    {
        cout<<0<<0<<0;
        return 0;
    }
    if(dr2[2]<='C'&&dx2[2]<='C')
    {
        cout<<1;
        if(dr2[2]=='B'||dx2[2]=='B')
        {
            cout<<1;
        }
        else
        {
        cout<<0;
        return 0;
        }
    }
    else if(dr2[2]>'C'&&dx2[2]>'C')
    {
        cout<<1<<1;
        return 0;
    }
    else
    {
        cout<<0<<0;
        return 0;
    }
    return 0;
}
