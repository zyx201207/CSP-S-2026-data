#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,l,r,ans;
struct node{
    int sum;
    char ch;
}a[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].sum>>a[i].ch;
    l=1,r=n;
    while(l<r)
    {
        int minn=min(a[l].sum,a[r].sum);
        a[l].sum-=minn;
        a[r].sum-=minn;
        if(a[l].ch!=a[r].ch) ans+=minn;
        if(a[l].sum==0) l++;
        if(a[r].sum==0) r--;
    }
    cout<<ans;
    return 0;
}
