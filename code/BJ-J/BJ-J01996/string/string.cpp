#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100];
long long l = 2;
long long ans,z;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    s += ' ';
    for(int i = 1; i <= n; i++)
    {
        char c;
        cin >> a[i] >> c;
        for(int j = 0; j < a[i]; j++)
        {
            s += c;
        }
        l += a[i];
    }
    z = l / 2;
    if(l % 2 == 0)
    {
        z++;
    }
    for(int i = 1; i <= z; i++)
    {
        if(s[i] != s[2 * z - i])
        {
            s[i] = s[2 * z - i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}
//Trick||Treat!
