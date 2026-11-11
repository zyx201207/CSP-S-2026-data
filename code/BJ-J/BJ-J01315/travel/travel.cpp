#include <bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int flag[4] = {0};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> c2 >> c3 >> c4;
    if(c1 == c3)
    {
        flag[0] = 1;
        if(c2[0] == c4[0] && c2[1] == c4[1])
        {
            flag[1] = 1;
            if((int(c2[2])-64 <= 3 && int(c4[2])-64 <= 3) || (int(c2[2])-64 > 3 && int(c4[2])-64 > 3))
            {
                flag[2] = 1;
                if(int(c2[2])-64 > 3 && int(c4[2])-64 > 3)
                {
                    flag[3] = 1;
                }
                else if(abs(int(c2[2])-int(c4[2])) == 1)
                {
                    flag[3] = 1;
                }
            }
        }
    }
    for(int i = 0;i < 4;i++)
    {
        cout << flag[i];
    }
    return 0;
}