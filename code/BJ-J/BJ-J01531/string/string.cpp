#include<iostream>
#include<string>
#define int long long
using namespace std;
const int MAXN=2e5;
struct Inte
{
    int l,r;
};
int a[MAXN+5];
char c[MAXN+5];
Inte b[MAXN+5];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i]>>c[i];
        b[i].l=b[i-1].r+1;
        b[i].r=b[i].l+a[i]-1;
        sum+=a[i];
    }
    a[0]=1e9+1;
    a[n+1]=1e9+1;
    int mid;
    for(int i=1;i<=n;++i)
    {
        if(b[i].l<=sum/2&&b[i].r>=sum/2)
        {
            mid=i;
            break;
        }
    }
    int l=1,r=n,ans=0;
    for(;l<=mid&&r>=mid;)
    {
        while(sum+1-b[r].l<b[l].r&&l<=n&&r>=1)
        {
            if(c[l]!=c[r])
            {
                ans+=a[r];
            }
            a[l]-=a[r];
            --r;
        }
        while(sum+1-b[l].r>b[r].l&&l<=n&&r>=1)
        {
            if(c[l]!=c[r])
            {
                ans+=a[l];
            }
            a[r]-=a[l];
            ++l;
        }
        if(sum+1-b[l].r==b[r].l&&l<=n&&r>=1)
        {
            if(c[l]!=c[r])
            {
                ans+=a[l];
            }
            ++l;
            --r;
        }
    }
    cout<<ans;
    return 0;
}
