#include<bits/stdc++.h>
using namespace std;

char abc[8][2];

int main()
{
    freopen("travel5.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b,c,d;
    cin>>a>>b>>c>>d;

    abc[0][0]='A';
    abc[0][1]='B';
    abc[1][0]='B';
    abc[1][1]='A';
    abc[2][0]='B';
    abc[2][1]='C';
    abc[3][0]='C';
    abc[3][1]='B';
    abc[4][0]='D';
    abc[4][1]='F';
    abc[5][0]='F';
    abc[5][1]='D';
    abc[6][0]='A';
    abc[6][1]='C';
    abc[7][0]='C';
    abc[7][1]='A';

    if(a!=c)
    {
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    if(b[0]!=d[0]||b[1]!=d[1])
    {
        cout<<"000";
        return 0;
    }
    cout<<"1";

    char e=b[2];
    char f=d[2];
    int i=0;
    for(;i<6;i++)
    {
        if(e==abc[i][0]&&f==abc[i][1])
        {
            cout<<"11";
            return 0;
        }
    }
    for(;i<8;i++)
    {
        if(e==abc[i][0]&&f==abc[i][1])
        {
            cout<<"10";
            return 0;
        }
    }
    cout<<"00";

    return 0;
}
