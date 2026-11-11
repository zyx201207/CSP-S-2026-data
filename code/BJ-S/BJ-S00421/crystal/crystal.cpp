#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long cost=0;
    int maxx=1;
    int l=1;
    for(int i=2;i<=n;i++)//lastneedans
    {
        cost=cost+(a[i]-a[i-1])*(i-1);//from pre
        while(cost>m)
        {
            cost-=(a[i]-a[l]);
            l++;
        }
        maxx=max(maxx,(i-l+1));
    }
    cout<<maxx;
    return 0;
}
