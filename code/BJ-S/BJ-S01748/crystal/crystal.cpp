#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    long long ans = 1,sum = 0;
    bool flag = true;
    for(int i = 1;i < n;i++)
    {
        if(a[i+1]-a[i] != 0)flag = false;
        sum += i * (a[i+1]-a[i]);
        if(sum <= m)ans++;
    }
    if(flag)cout << m << endl;
    else cout << ans << endl;
    return 0;
}
