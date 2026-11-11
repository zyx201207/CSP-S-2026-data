#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum,m,t[500005];
int n,maxm;
bool p=0,p1=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) t[i]=a[i]-a[i-1];
    for(int i=3;i<=n;i++)
    {
        if(t[i]!=t[i-1]) p1=1;
    }
    for(int i=2;i<=n;i++)
    {
        sum+=t[i]*(i-1);
        if(sum>m)
        {
            maxm=i-1;
            break;
        }
    }s
    if(sum<=m) maxm=n;
    if(p1==0)
    {
    cout<<maxm;
        return 0;
    }
    else
    {
        for(int i=2;i<=n-maxm;i++)
        {
            sum=0;
            for(int j=i+1;j<=n;j++)
            {
                if(j<=i+maxm+1&&sum+t[maxm]*maxm>m) break;
                else sum+=t[j]*(j-i+1);
                if(sum>m)
                {
                    maxm=max(maxm,j-i+1);
                    break;
                }
            }
        }
        cout<<maxm;
    }
    return 0;
}
