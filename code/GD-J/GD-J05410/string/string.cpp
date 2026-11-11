#include <iostream>
#include <string>
using namespace std;

const int N = 2 * 1e5 + 1;

int nums[N];
char cs[N];

int main()
{
    freopen("string1.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n, len = 0;
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i] >> cs[i];
        for (int j = 0; j < nums[i]; ++j)
            s += cs[i];
        len += nums[i];
    }

    int ans = 0;
    for (int i = 0; i < len / 2; ++i)
        if (s[i] != s[len - i - 1])
            ++ans;
    
    cout << ans << endl;
    return 0;
}
