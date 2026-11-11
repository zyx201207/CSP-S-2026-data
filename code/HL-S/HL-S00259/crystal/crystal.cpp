#include<bits/stdc++.h>
using namespace std;
long long a[10000000],b[100000000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        b[i] = a[i]-a[i-1];
    }
    sort(b+1,b+n+1);
    int ans = 0,cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        if(b[i] < m)
        {
            cnt+=b[i];
            ans++;
        }
        if(cnt >= m)
        {
            break;
        }
    }
    cout << ans;
    return 0;
}


