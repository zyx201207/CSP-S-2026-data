#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    string a[n+3];
    string c[n+3];
    int s[n+3];
    long long h = 0;
    long long ans = 0;
    for(int i = 0;i <= n;i++)
    {
        cin >> s[i] >> a[i];
        for(int j = 1;j <= s[i];j++)
        {
            c[i] = a[i];
            h += s[i];
        }
    }
    for(int i = 0;i <= h / 2;i++)
    {
        if(c[i] != c[h-1-i]) ans++;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
