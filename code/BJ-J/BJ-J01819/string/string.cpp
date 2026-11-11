#include <bits/stdc++.h>
using namespace std;
//#define int long long
struct stu
{
    int a;
    char ch;
};
stu s[200005];
signed main()
{
    //freopen("string6.in","r",stdin);
    //freopen("string6.out","w",stdout);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i].a >> s[i].ch;
    }
    long long cnt = 0;
    int l = 1,r = n;
    while(l < r)
    {
        int t = min(s[l].a,s[r].a);
        if(s[l].ch != s[r].ch)
        {
            cnt += t;
        }
        s[l].a -= t;
        s[r].a -= t;
        //cout << s[l].a << " " << s[r].a << "\n";
        if(s[l].a == 0)
        {
            l++;
            //cout << "1 ";
        }
        if(s[r].a == 0)
        {
            r--;
            //cout << "2 ";
        }
        //cout << l << " " << r << "\n";
    }
    cout << cnt;
    return 0;
}
