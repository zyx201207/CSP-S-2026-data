#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool check1(char x,char y)
{
    if(x=='A'&&(y=='B'||y=='C')||x=='B'&&(y=='A'||y=='C')||x=='C'&&(y=='A'||y=='B')) return 1;
    if(x=='D'&&y=='F'||x=='F'&&y=='D') return 1;
    return 0;
}
bool check2(char xx,char yy)
{
    if(xx=='A'&&yy=='B'||xx=='B'&&(yy=='A'||yy=='C')||xx=='C'&&yy=='B') return 1;
    if(xx=='D'&&yy=='F'||xx=='F'&&yy=='D') return 1;
    return 0;
}
int main()

{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c) cout<<'1';
    else
    {
        cout<<"0000";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1]) cout<<'1';
    else
    {
        cout<<"000";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(check1(b[2],d[2])) cout<<'1';
    else
    {
        cout<<"00";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(check2(b[2],d[2])) cout<<'1';
    else cout<<'0';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
