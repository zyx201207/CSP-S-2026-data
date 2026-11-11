#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long a[MAXN],f[MAXN];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int L=i,R=n;
        while(L<=R)
        {
            int mid=(L+R)>>1;
            if(f[mid]-f[i-1]-(i-1)*(a[mid]-a[i-1])<=m)
            {
                ans=max(ans,mid-i+1);
                L=mid+1;
            }
            else
                R=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
