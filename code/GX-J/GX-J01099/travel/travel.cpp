# include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,x,y;
    cin >> a >> b >> x >> y;
    string bans,yans;
    if(a == x)
    {
        cout << "1";
        for (int i = 0;i <= b.size();i++)
        {
            if(b[i] >= '0' && b[i] <= '9')
            {
                bans += b[i];
            }
        }
        for (int i = 0;i <= y.size();i++)
        {
            if(y[i] >= '0' && y[i] <= '9')
            {
                yans += y[i];
            }
        }
        if (bans == yans)
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
        if ((b[2] == 'A' && y[2] == 'B') || (b[2] == 'A' && y[2] == 'C') || (b[2] == 'B' && y[2] == 'A') || (b[2] == 'B' && y[2] == 'C') || (b[2] == 'C' && y[2] =='A') || (b[2] == 'C' && y[2] =='B') || (b[2] == 'D' && y[2] == 'F') || (b[2] == 'F' && y[2] == 'D'))
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
        if ((b[2] == 'A' && y[2] == 'B') || (b[2] == 'B' && y[2] == 'C') || (b[2] == 'B' && y[2] == 'A') || (b[2] == 'C' && y[2] == 'B') || (b[2] == 'D' && y[2] == 'F') || (b[2] == 'F' && y[2] == 'D'))
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    else
    {
        cout << "0000";
    }
    return 0;
}

