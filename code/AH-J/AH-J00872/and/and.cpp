#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,k;
int a[N],f[N],maxn;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i],maxn=max(maxn,a[i]);
    if(k==1)
    {
        cout<<maxn<<endl;
        return 0;
    }
    for(int i=n;i>=1;i--)
        for(int j=k;j>=1;j--)
        {
            if(j==1)
                f[j]=a[i];
            else
            {
				int t=f[j-1]&a[i];
                f[j]=max(f[j],t);
			}
        }
    cout<<f[k]<<endl;
    return 0;
}
