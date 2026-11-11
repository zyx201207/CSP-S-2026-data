#include<bits/stdc++.h>
using namespace std;
int n, a[200010];
char c[200010];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
    }
    int zfc = 1;
    while(true)
    {
        if(a[zfc] > 0)
        {
            s += c[zfc];
            a[zfc]--;
        }
        else
        {
            zfc++;
        }
        if(a[n] == 0)
        {
            break;
        }
    }
    int len = s.size();
    int l = 1, r = len, cnt = 0;
    while(r > l)
    {
        if(s[l] != s[r])
        {
            cnt++;
        }
        l++;
        r--;
    }
    cout << cnt;
    return 0;
}
