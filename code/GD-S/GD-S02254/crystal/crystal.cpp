#include <bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m;
long long a[500010];
int main()
{   freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int ma=1,l=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
    {
        if((a[i+1]-a[i])*ans<=m)
        {
            m-=(a[i+1]-a[i])*ans;
            ans++;
            ma=max(ans,ma);

        }
        else
        {
            ans--;
            m+=(a[i]-a[l]);
            i--;
            l++;

        }
    }
    cout<<ma;


//i

    return 0;
}
