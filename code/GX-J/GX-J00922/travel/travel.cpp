#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >>a>>b>>c>>d;
    if(a==c&&b==d)
    {
        cout <<0000;
        return 0;
    }
    else cout <<1;
    if(a==c) cout <<1;
    else cout <<0;
    if(a==c&&b[1]==d[1]&&b[0]==d[0]&&((b[2]=='D'&&b[2]=='F')||(b[2]=='F'&&b[2]=='D'))||(b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')) cout <<1;
    else cout <<0;
    if(a==c&&b[1]==d[1]&&b[0]==d[0]&&(b[2]=='A'&&d[2]=='B')||(b[2]=='C'&&d[2]=='B')||(b[2]=='F'&&d[2]=='D')) cout <<1;
    else cout <<0;
    return 0;
}
