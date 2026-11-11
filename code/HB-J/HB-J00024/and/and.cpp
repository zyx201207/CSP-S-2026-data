#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int a[N],st[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int ans=0;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=30;i>=0;i--)
    {
        ans*=2;
        int siz=0;
        for (int j=1;j<=n;j++)
        {
            if (st[j]) continue;
            if ((a[j]>>i)&1) siz++;
        }
        if (siz>=m)
        {
            ans++;
            for (int j=1;j<=n;j++)
            {
                if (((a[j]>>i)&1)==0) st[j]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
