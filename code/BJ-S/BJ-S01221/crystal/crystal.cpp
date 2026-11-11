#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m;
    int ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        int k=m,sum=1;
        for(int j=i-1;j>=1;j--)
        {
            if(a[i]!=a[j])
            {
                if(k>=(a[i]-a[j]))
                {
                    k-=(a[i]-a[j]);
                    sum++;
                }
            }

            else
            {
                sum++;
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}