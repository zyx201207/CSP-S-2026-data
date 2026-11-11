#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, c;
    char b[3], d[3];
    cin >> a >> b >> c >> d;
    char arr[4] = {'0'};
    bool n;
    if (a == c)
    {
        arr[0] = '1';
        if (b[0] == d[0] && b[1] == d[1])
        {
            arr[1] = '1';
            char q = b[2], p = d[2];
            if ((q == 'A' && p == 'B') || (q == 'C' && p == 'B'))
            {
                arr[2] = '1';
                arr[3] = '1';
            }
            else if ((q == 'B' && p == 'A') || (q == 'B' && p == 'C'))
            {
                arr[2] = '1';
                arr[3] = '1';
            }
            else if ((q == 'C' && p == 'A') || (q == 'A' && p == 'C'))
            {
                arr[2] = '1';
                arr[3] = '0';
            }
            else if ((q == 'D' && p == 'E') || (q == 'E' && p == 'D'))
            {
                arr[2] = '1';
                arr[3] = '1';
            }
            else
            {
                arr[2] = '0';
                arr[3] = '0';
            }
        }
        else
        {
            arr[1] = '0';
            arr[2] = '0';
            arr[3] = '0';
        }
    }
    else{
        arr[0] = '0';
        arr[1] = '0';
        arr[2] = '0';
        arr[3] = '0';
    }
    cout << arr << endl;
    return 0;
}
