#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010][2],sum;
char ch;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i][0] >> ch;
        a[i][1] = ch;
        sum += a[i][0];
    }
    int l = 0,r = 0,i = 1,j = n;
    sum = 0;
    while(i < j)
    {
        l += a[i][0];
        r += a[j][0];
        if(a[i][1] != a[j][1]) sum += min(a[i][0],a[j][0]);
        if(l < r) a[i][0] = 0;
        else if(r < l) a[j][0] = 0;
        else a[i][0] = 0,a[j][0] = 0;
        while(l < r)
        {
            a[i][0] = 0;
            i++;
            int t = 0;
            if(a[i][0] + l > r) t = r - l;
            else t = a[i][0];
            a[i][0] -= t;
            if(a[i][1] != a[j][1]) sum += t;
            l += t;
            a[j][0] = 0;
        }
        while(r < l)
        {
            a[j][0] = 0;
            j--;
            int t = 0;
            if(a[j][0] + r > l) t = l - r;
            else t = a[j][0];
            a[j][0] -= t;
            if(a[j][1] != a[i][1]) sum += t;
            r += t;
            a[i][0] = 0;
        }
        if(!a[i][0]) i++;
        if(!a[j][0]) j--;
    }
    cout << sum << endl;
    return 0;
}
