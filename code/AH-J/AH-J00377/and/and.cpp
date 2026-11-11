#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
int n,m;
int ewy[200010];
int f[300010];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1)
    {
        int maxn=0;
        for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
        cout<<maxn<<endl;
        return 0;
    }
    else if(m==2)
    {
        int maxn=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int ewy=a[i]&a[j];
                maxn=max(maxn,ewy);
            }
        }
        cout<<maxn<<endl;
        return 0;
    }
    else
    {
        for(int i=0;i<=m;i++) f[i]=pow(2,25)-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=m;j>=1;j--)
            {
                f[j]=max(f[j],f[j-1]&a[i]);
            }
            cout<<endl;
        }
        cout<<f[m];
    }
}
