#include <bits/stdc++.h>
using namespace std;
long long a[500001];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,l=0,r=0,maxn=0;
    long long m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(l==r)
        l=++r;
        else
        {
            sum-=(a[r]-a[l++]);
        }
        while(r<n)
        {
            long long x=(r-l+1)*(a[r+1]-a[r]);
            if(x+sum<=m)
            {
                sum+=x;
                ++r;
            }
            else
            break;
        }
        maxn=max(maxn,r-l+1);
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
