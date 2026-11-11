#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    char c[n];
    for (int i = 0; i < n; i++)
        cin >> a[i] >> c[i];
    long long ans = 0;
    int i = 0, j = n - 1;
    int ai = a[0], aj = a[n - 1];
    while (i != n || j != -1)
    {
        if (c[i] != c[j])
        {
            if (ai > aj)
            {
                ans += aj;
                ai -= aj;
                j--;
                aj = a[j];
            }
            else if (ai < aj)
            {
                ans += ai;
                aj -= ai;
                i++;
                ai = a[i];
            }
            else
            {
                ans += ai;
                i++;
                j--;
                ai = a[i];
                aj = a[j];
            }
        }
        else
        {
            if (ai > aj)
            {
                ai -= aj;
                j--;
                aj = a[j];
            }
            else if (ai < aj)
            {
                aj -= ai;
                i++;
                ai = a[i];
            }
            else
            {
                i++;
                j--;
                ai = a[i];
                aj = a[j];
            }
        }
    }
    cout << ans / 2;
    return 0;
}
