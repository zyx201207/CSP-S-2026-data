#include<bits/stdc++.h>
using namespace std;
int s[1000000],a[1000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans = 0;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i];
        for(int j = n;j >=1;j--)
        {
            a[i] = s[i];
        }
        if(a[i] = s[i])
        {
            ans++;
        }
    }
    if(ans == n)
    {
        cout << 0;
    }
    return 0;
}
