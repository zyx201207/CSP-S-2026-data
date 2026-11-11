#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a,c;
    char b[5],d[5];

    cin>>a;
    for(int i=1;i<=3;i++)
    {
        cin>>b[i];
    }
    cin>>c;
    for(int i=1;i<=3;i++)
    {
        cin>>d[i];
    }


    if(a==c)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }

    if(a==c&&b[2]==d[2])
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }

    if(a==c && (b[2]==d[2]&&b[1]==d[1]) && ( (b[3] == 'D' || b[3] == 'F') && (d[3] == 'D' || d[3] == 'F') ) )
    {
        cout<<1;
    }
    else if(a==c && (b[2]==d[2]&&b[1]==d[1]) && ( ( b[3]== 'A' || b[3]== 'B' || b[3]== 'C' ) && ( d[3]=='A' || d[3]=='B' || d[3]=='C') ) )
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }

    if(a==c && (b[2]==d[2]&&b[1]==d[1]) && abs(b[3]-d[3])==1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
