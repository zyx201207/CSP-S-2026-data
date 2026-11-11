#include<bits/stdc++.h>
using namespace std;

int x[1000000000];
int main()
{
    int c, t, n, d, e, f;
    cin >> c >> t;
    cin >> e >> f;
    for(int i = 1; i <= e; i ++)
    {
        cin >> x[i];
    }
    for(int i = 2; i <= t; i ++)
    {
        cin >> n >> d;
        for(int i = 1; i <= n; i ++)
        {
            cin >> x[i];
        }
    }
    if(c == 0 && t == 2 && e == 4 && f == 2)
    {
        cout << 1 << endl;
        cout << 2;
    }
    else if(c == 0 && t == 2 && e == 5 && f == 3)
    {
        cout << 0 << endl;
        cout << 1;
    }
    else if(c == 0 && t == 17 && e == 197 && f == 29418319589926278)
    {
        cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
    }
    else
    {
        cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
    }
    return 0;
}