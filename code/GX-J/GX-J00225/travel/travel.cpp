#include <bits/stdc++.h>
using namespace std;
void sv();
void fre()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("travel.in","r", stdin);
    freopen("travel.out","w",stdout);
}
signed main()
{
    fre();
    signed T = 1; //cin >> T;
    while (T--) sv();
    return 0;
}

using ll = long long;

void sv()
{
    int c1, c2;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int p1 = (s1[0]-'0') * 10 + (s1[1]-'0');
    int p2 = (s2[0]-'0') * 10 + (s2[1]-'0');
    int x1 = s1[2]-'A'+1, x2 = s2[2]-'A'+1;
    //cout << c1 <<' '<< c2 <<' '<< p1 <<' '<< p2 <<' '<< x1 <<' '<< x2 <<" \n ";
    if (c1 == c2)
    {
        cout << 1;
        if (p1 == p2)
        {
            cout << 1;
            if ((x1==1&&x2==2)||(x1==2&&x2==1)||(x1==1&&x2==3)||(x1==3&&x2==1)||(x1==2&&x2==3)||(x1==3&&x2==2)||(x1==4&&x2==5)||(x1==5&&x2==4))
            {
                cout << 1;
                if (abs(x1-x2) == 1)
                    cout << 1;
                else cout << 0;
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
}
