#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+100;
int n,m,a[N],diff[N],sum[N];
void bf()
{
    int maxx=1;
    for(int len=n;len>=2;len--)
    {
        for(int i=1;i<=n-len;i++)
        {
            int j=i+len,num=0,idx=0;
            for(int k=i;k<=j;k++)
            {
                if(num+a[j]-a[k]<=m)
                    num+=a[j]-a[k],idx=k;
                else
                    break;
            }
            maxx=max(idx-i+1,maxx);
        }
    }
    cout<<maxx<<endl;
    return;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=16)
    {
        bf();
        return 0;
    }
    for(int i=1;i<=n;i++)
        diff[i]=a[i]-a[i-1],sum[i]=sum[i-1]+diff[i]*(i-1);
    int k=upper_bound(sum+1,sum+n+1,m)-sum;
    if(k==n+1)
        cout<<n<<endl;
    else
        cout<<k-1<<endl;
    return 0;
}
