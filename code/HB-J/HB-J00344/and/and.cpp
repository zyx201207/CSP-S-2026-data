#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
long long a[200100];
long long ans,p[200100];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = n;i >= m;i--)
    {
        ans = int(a[i] & a[i-1]);
    }
    if(ans == 0)
    {
        cout << a[n];
        return 0;
    }
    cout << ans;
    return 0;
}
