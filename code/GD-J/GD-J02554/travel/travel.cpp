#include <bits/stdc++.h>
using namespace std;

bool check2(char x,char y)
{
    if (x=='A'&&y=='B') return 1;
    else if (x=='B'&&y=='A') return 1;
    else if (x=='B'&&y=='C') return 1;
    else if (x=='C'&&y=='B') return 1;
    else if (x=='F'&&y=='D') return 1;
    else if (x=='D'&&y=='F') return 1;
    else return 0;
}

bool check1(char x,char y)
{
    int a,b;
    if (x=='A'||x=='B'||x=='C')
    {
        a=1;
    }
    else a=2;

    if (y=='A'||y=='B'||y=='C')
    {
        b=1;
    }
    else b=2;
    if (a==b) return 1;
    else return 0;
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ri,xi,rt,xt;
    cin >> ri >> rt >> xi >> xt;
    if (ri==xi)
    {
        cout << 1;
        if (rt[0]==xt[0]&&rt[1]==xt[1])
        {
            cout << 1;
            if (check1(rt[2],xt[2])==1)
            {
                cout << 1;
                if (check2(rt[2],xt[2])==1)
                {
                    cout << "1";
                }
                else cout <<"0";
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
