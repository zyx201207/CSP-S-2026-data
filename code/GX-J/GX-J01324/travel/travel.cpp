#include <bits/stdc++.h>
using namespace std;
string a[5], b[5];
bool x[7];
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a[1] >> a[2] >> b[1] >> b[2];
    if(a[1] == b[1])
    {
        x[1] = 1;
        if(a[2][0] == b[2][0]&&a[2][1]==b[2][1])
        {
            x[2] = 1;
            if((a[2][2] <= 'C')==(b[2][2] <= 'C'))
            //if(cmp(a[2][2], b[2][2]))
            {
                x[3] = 1;
                if((a[2][2] - b[2][2] == 1||a[2][2] - b[2][2] == -1)||(a[2][2] == 'D'&&b[2][2] == 'F')||(a[2][2] == 'F'&&b[2][2] == 'D'))
                    x[4] = 1;
            }
        }
    }
    printf("%d%d%d%d", x[1], x[2], x[3], x[4]);
    return 0;
}
