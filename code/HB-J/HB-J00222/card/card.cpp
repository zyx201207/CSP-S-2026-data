#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("crad.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    long long cnt[m] = {0},num[n + 5];
    for (long long i = 1;i <= n;i++)
    {
        cin >> num[i];
    }
    if (m = 1)
    {
        cout << 1;
    }
    if (m == 2)
    {
        if (n == 1)
        {
            if (num[1] == 1)
            {
                cout << 1 << " " << 0;
            }
            else
            {

                cout << 0 << " " << 1;
            }
        }
        if (n == 2)
        {
            if (num[1] == num[2])
            {
                if (num[1] == 1)
                {
                    cout << 1 << " " << 0;
                }
                else
                {

                    cout << 0 << " " << 1;
                }
            }
            else
            {
                    cout << 1 << " " << 1;
            }

        }
        if (n == 3)
        {
            if (num[1] == num[2] && num[3] == num[2])
            {
                if (num[1] == 1)
                {
                    cout << 1 << " " << 0 << " " << 0;
                }
                else if (num[1] == 2)
                {
                    cout << 0 << " " << 1 << " " << 0;
                }
                else
                {
                    cout << 0 << " " << 0 << " " << 1;
                }
            }
            else if(num[1] == num[2] && num[3] != num[2])
            {
                if (num[1] == 1)
                {
                    if (num[3] == 2)
                    {
                        cout << 1 << " " << 1 << " " << 0;
                    }
                    if (num[3] == 3)
                    {
                        cout << 1 << " " << 0 << " " << 1;
                    }
                }
                else if (num[1] == 2)
                {
                    if (num[3] == 1)
                    {
                        cout << 1 << " " << 1 << " " << 0;
                    }
                    if (num[3] == 3)
                    {
                        cout << 0 << " " << 1 << " " << 1;
                    }
                }
                else
                {
                    if (num[3] == 1)
                    {
                        cout << 1 << " " << 0 << " " << 1;
                    }
                    if (num[3] == 2)
                    {
                        cout << 0 << " " << 1 << " " << 1;
                    }
                }
            }
            else if(num[1] != num[2] && num[3] == num[2])
            {
                if (num[3] == 1)
                {
                    if (num[1] == 2)
                    {
                        cout << 1 << " " << 1 << " " << 0;
                    }
                    if (num[1] == 3)
                    {
                        cout << 1 << " " << 0 << " " << 1;
                    }
                }
                else if (num[3] == 2)
                {
                    if (num[1] == 1)
                    {
                        cout << 1 << " " << 1 << " " << 0;
                    }
                    if (num[1] == 3)
                    {
                        cout << 0 << " " << 1 << " " << 1;
                    }
                }
                else
                {
                    if (num[1] == 1)
                    {
                        cout << 1 << " " << 0 << " " << 1;
                    }
                    if (num[1] == 2)
                    {
                        cout << 0 << " " << 1 << " " << 1;
                    }
                }
            }
            else
            {
                cout << 1 << " " << 1 << " " << 1;
            }
        }
    }
}
