#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int n, a[N], siz, ans;
char c[N];
string s = "";
signed main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);

    cin >> n;
    if(n <= 10)
    {
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            char t;
            cin >> t;
            while(x--) s += t;
        }
        for(int i=0;i<s.size()/2+1;i++)
        {
            if(s[i] != s[s.size()-i-1])
            {
                s[s.size()-i-1] = s[i];
                ans++;
            }
        }
        cout<<ans;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
