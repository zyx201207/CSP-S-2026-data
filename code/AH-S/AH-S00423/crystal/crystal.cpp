#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,m;
int a[6000050];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    //input
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }

    //sort
    sort(a+1,a+n+1);

    //left & right
    int l = 1,r = 1;
    int sum = a[1];
    int maxn = 0;
    while(r <= n)
    {
        if(a[r] * (r-l+1) - m > sum)
        {
            //wrong
            sum -= a[l];
            l++;
        }
        else
        {
            //OK
            maxn = max(maxn,r-l+1);
            r++;
            sum += a[r];
        }
    }

    //output
    cout << maxn;

    return 0;
}
