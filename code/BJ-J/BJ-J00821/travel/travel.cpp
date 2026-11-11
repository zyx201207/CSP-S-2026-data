#include <bits/stdc++.h>
using namespace std;
int nub[10];
struct seat
{
    int a;
    string b;
};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    seat d[10];
    for (int i = 1;i <= 2;i++)
    {
        cin >> nub[i];
        cin >> d[i].a >> d[i].b;
    }
    if (nub[1] != nub[2])
    {
        cout << "0000";
        return 0;
    }
    else
    {
        if (d[1].a == d[2].a)
        {
            if ((d[1].b <= "C" && d[2].b <= "C") || (d[1].b >= "D" && d[2].b >= "D"))
            {
                if (d[1].b >= "D" && d[2].b >= "D")
                {
                    cout << "1111";
                    return 0;
                }
                else
                {
                    if (d[1].b == "B" || d[2].b == "B")
                    {
                        cout << "1111";
                        return 0;
                    }
                }
                cout << "1110";
                return 0;
            }
            cout << "1100";
            return 0;
        }
        else
        {
            cout << "1000";
            return 0;
        }
    }
    return 0;
}