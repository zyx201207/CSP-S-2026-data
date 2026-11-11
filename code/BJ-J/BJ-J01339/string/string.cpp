#include  <iostream>
using namespace std;
int a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long sum = 0;
    long long ans = 0;
    string s;
    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
        cin >> c[i];
        for (int j = 1;j <= a[i]; j++)
        {
            s += c[i];
        }
        sum += a[i];
    }
    for (int i = 0; i <= sum - 1; i++)
    {
        if (s[i] != s[sum - i - 1])
        {
            ans++;
        }
    }
    cout << ans / 2;
    return 0;
}
