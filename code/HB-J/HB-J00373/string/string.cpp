#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,k;
    long long a,j = 0,cnt = 0;
    char b;
    bool flag = true;
    string s;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a >> b;
        for(long long i = 1;i <= a;i++)
        {
            s[j] = b;
            j++;
        }
    }
    if(j % 2 == 1)
    {
        k = j / 2;
    }
    else
    {
        k = j / 2 - 1;
    }
    for(long long i = 0;i <= k;i++)
    {
        if(s[i] != s[j - 1 - i])
        {
            cnt++;
            flag = false;
        }
    }
    if(flag)
    {
        cout << 0;
        return 0;
    }
    cout << cnt;
    return 0;
}
