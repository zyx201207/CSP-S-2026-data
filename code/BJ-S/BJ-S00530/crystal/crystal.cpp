#include<bits/stdc++.h>

#define lowbit(x) (x&-x)
#define int long long

using namespace std;

namespace cyan
{
    constexpr int N=5e5+5;

    inline int read()
    {
        int x=0;bool f=0;
        char ch=getchar();
        while(ch<'0' || ch>'9') f^=ch=='-',ch=getchar();
        while(ch<='9' && ch>='0') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
        return f?-x:x;
    }

    inline int min(int a, int b) {return a<b?a:b;}

    inline int max(int a, int b) {return a>b?a:b;}
}

using namespace cyan;

int n,m;
int a[N];
int s[N];
int ans=0;

int find(int p)
{
    int l=1,r=p;
    int mid;
    while(l<=r)
    {
        mid=l+r>>1;
        if(a[p]*(p-mid+1)-s[p]+s[mid-1]<=m) r=mid-1;
        else l=mid+1; 
    }
    return r+1;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1, a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++) ans=max(ans, i-find(i)+1);
    cout<<ans<<'\n';

    return 0;
}
