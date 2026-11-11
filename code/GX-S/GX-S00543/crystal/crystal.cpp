#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],s[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,l=1,an=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        while(l<=i&&((i-l+1)*a[i]-(s[i]-s[l-1])>m))
        {
            l++;
        }
        an=max(an,i-l+1);
    }
    cout<<an<<endl;
    return 0;
}
