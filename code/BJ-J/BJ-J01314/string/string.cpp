#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans = 0,sum = 0;
    string s = "";
    cin >> n;
    for(int i = 1;i <= n;i++)
    {

        long long num;
        char c;
        cin >> num >> c;
        sum += num;
        for(int j = 1;j <= num;j++)
        {
            s += c;
        }
    }
    for(int i = 0;i <= sum / 2;i++)
    {
        if(s[i] != s[sum - i - 1]) ans++;
    }
    cout << ans << endl;
    return 0;
}
