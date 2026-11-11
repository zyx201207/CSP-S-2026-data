#include <bits/stdc++.h>
using namespace std;
struct T
{
    long long a;
    char c;
}t[200005];
int n;
long long sum,ans,cnt;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    string s = "1";
    for(int i = 1;i <= n;i++)
    {
        cin >> t[i].a >> t[i].c;
        for(int j = 1;j <= t[i].a;j++)
            s += t[i].c;
        sum += t[i].a;
    }
    for(int i = 1;i <= (sum + 1) / 2;i++)
    {

        if(s[i] != s[sum - i + 1])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
