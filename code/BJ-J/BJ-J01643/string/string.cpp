#include <bits/stdc++.h>
using namespace std;



int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long int n;
    cin >> n;
    string input;
    for (int i = 0;i <= n;i++)
    {
        long long int x;
        string ch;
        cin >> x;
        cin >> ch;
        for (int i = 0;i < x;i++)
        {
            input += ch;
        }
    }

    int ans = 0;
    int s = input.size();
    for (int i = 0;i < s / 2;i++)
    {
        int j = s - i - 1;

        if (input[i] != input[j]) ans++;

    }


    cout << ans;
    return 0;
}
