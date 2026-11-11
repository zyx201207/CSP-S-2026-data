#include<bits/stdc++.h>
using namespace std;
const  int maxn = 5e5+5;
long long n,m,a[maxn],k,dt[maxn],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    ans = n;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    k = a[(n/2)+1];
    for(int i = 1;i<=n;i++)
    {
        dt[i] = k - a[i];
    }
    for(int i = 1;i<=n;i++)
    {
        if(dt[i]<0||dt[i]>m) ans--;
    }
    cout<<ans;
    return 0;
}
