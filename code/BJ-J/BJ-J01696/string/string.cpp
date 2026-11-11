#include <iostream>
using namespace std;

long long a[200010];
char c[200010];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cin >> c[i];
        for (int j = 1; j <= a[i]; j++)
        {
            s = s +c[i];
        }
    }
    long long cnt = 0;
    for (int i = 0; i <= s.size()/ 2; i++)
    {
        if (s[i] != s[s.size() - i - 1]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
