#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],an;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(n==m)
    {
        an=a[1];
        for(int i=1;i<=n;i++)
        {
            an&=a[i];
        }
        cout << an;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=m;i<=n;i++)
    {
        long long ans=a[i-m+1];
        for(int j=i-m+1;j<=i;j++)
        {
            ans=(ans&a[j]);
        }
        an=max(ans,an);
    }
    cout << an;
    return 0;
}
