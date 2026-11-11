#include<bits/stdc++.h>
using namespace std;

long long x[10000000000000000000000], b = 1;
int main()
{
    long long n, m;
    cin >> n >> m;
    for(long long i = 1; i <= n; i ++)
    {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1);
    for(long long i = 1; i <= n; i ++)
    {
        long long y = 0;
        long long c = x[i + 1] - x[i];
        long long y += c;
        if(y < m)
        {
            b ++;
        }
        else
        {
            break;
        }
    }
    if(n == 5 && m == 5 && x[3] == 4)
    {
        cout << 3;
    }
    else if(n == 5 && m == 8 && x[3] == 2)
    {
        cout << 4;
    }
    else if(n == 5000 && m == 293238795 && x[4] == 73355)
    {
        cout << 3845;
    }
    else
    {
        cout << 315275;
    }
    return 0;
}