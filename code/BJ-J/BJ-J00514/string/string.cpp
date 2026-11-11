
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    int n , ans = 0;
    string s1 , s2;
    char c;
    cin >> n;

    for (int i = 1 , node;i <= n;i++)
    {
        cin >> node >> c;
        while (node--)
        {
            s1 = s1 + c;
        }
    }
    int len = s1.size();
    for (int i = 0;i <= len - 1;i++)
    {
        s2[i] = s1[len - i - 1];
        if (s2[i] != s1[i])
        {
            ans++;
        }
    }
    cout << ans / 2 << endl;
    return 0;
}
