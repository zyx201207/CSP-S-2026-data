#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
//注意先审题，再写，不要死磕，不要用复杂算法

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a==c)cout << "1";
    else
    {
        cout << "0000";
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1])cout << "1";
    else
    {
        cout << "000";
        return 0;
    }
    if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&b[2]>'C'))cout << "1";
    else
    {
        cout << "00";
        return 0;
    }
    if(b[2]==d[2]+1||d[2]==b[2]+1)cout << "1";
    else
    {
        cout << "0";
        return 0;
    }
    return 0;
}
