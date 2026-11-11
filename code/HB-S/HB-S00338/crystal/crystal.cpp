#include <bits/stdc++.h>
using namespace std;

int n,ans;
long long m,a[500005],ch[500005];
bool flag;

bool check(int mid)
{
    long long cnt = 0;
    for(int i = 1;i <= n-mid+1;i++)
    {
        cnt = 0;
        for(int j = 1;j < mid;j++)
            cnt += ch[i+j-1]*j;
        if(cnt <= m) break;
    }
    return cnt <= m;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++)
    {
        ch[i-1] = a[i]-a[i-1];
        if(i > 2)
            if(ch[i-1] != ch[i-2])
                flag = 1;
    }
    if(!flag)
    {
        long long c = ch[1];
        ans = sqrt(m*2/c)+1;
        cout << ans;
    }
    else
    {
        int l = 1,r = n;
        while(l < r)
        {
            int mid = (l+r)/2+1;
            if(check(mid))
            {
                ans = mid;
                l = mid;
            }
            else
            {
                r = mid-1;
            }
        }
        cout << ans;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
