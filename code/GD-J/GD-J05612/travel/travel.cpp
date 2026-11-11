#include <iostream>
using namespace std;
#define LL long long
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    char train1[3], seat1[4], train2[3], seat2[4];
    cin >> train1 >> seat1 >> train2 >> seat2;
    char statu1 = '1';
    for (LL i = 0; i < 3; ++i)
    {
        if (train1[i] != train2[i])
        {
            statu1 = '0';
        }
    }
    char statu2 = '1';
    if (statu1 == '1')
    {
        for (LL i = 0; i < 2; ++i)
        {
            if (seat1[i] != seat2[i])
            {
                statu2 = '0';
            }
        }
    }
    else
    {
        statu2 = '0';
    }
    char statu3 = '0';
    if (statu2 == '1')
    {
        if ((seat1[2] == 'A' || seat1[2] == 'B' || seat1[2] == 'C') && (seat2[2] == 'A' || seat2[2] == 'B' || seat2[2] == 'C'))
        {
            statu3 = '1';
        }
        else if ((seat1[2] == 'D' || seat1[2] == 'F') && (seat2[2] == 'D' || seat2[2] == 'F'))
        {
            statu3 = '1';
        }
    }
    else
    {
        statu3 = '0';
    }
    // char x[1][5] = {'A', 'B', 'C', 'D', 'F'};
    char statu4 = '0';
    if (statu3 == '1')
    {
        if (abs(seat1[2] - seat2[2]) == 1)
        {
            statu4 = '1';
        }
    }
    else
    {
        statu4 = '0';
    }
    cout << statu1 << statu2 << statu3 << statu4;
    return 0;
}
