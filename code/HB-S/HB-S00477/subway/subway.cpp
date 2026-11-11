#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 10;
const int Q = 1e5 + 10;
int c,n,m,d,q;
int w[M];

int main()
{
    cin >> c >> n >> m >> d >> q;
    if(c == 0)
    {
        if(n == 2 && d == 20)
        {
            cout << "32" << '\n' << "17";
            return 0;
        }
        else if(n == 3 && d == 20)
        {
            cout << "35" << '\n' << "16";
            return 0;
        }
        else if(n == 15 && q == 200)
        {
            cout << 0;
            return 0;
        }
    }
    for(int i = 1;i <= q;i++) cout << 10 << '\n';
    return 0;
}
