#include <bits/stdc++.h>
using namespace std;
long long n, a,ans;
string c, str1,str2, str3;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {

        cin >> a >> c;
        for (long long j = 1; j <= a; j++)
        {
            str1 += c;
        }
    }
    for (long long i = 0; i < str1.size()/2; i++)
    {
        str2+=str1[i];
        str3+=str1[str1.size()-1-i];
    }
    for (long long i = 0; i < str2.size(); i++)
    {
        if (str2[i] != str3[i])
            ans++;
    }
    cout << ans;
}

