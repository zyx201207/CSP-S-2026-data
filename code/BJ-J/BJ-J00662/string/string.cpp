#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
const int maxN=2e5+5;
int a[maxN];
char c[maxN];
int qzh[maxN];

int f(int q)
{
    for(int i=1;i<=n;i++)
        if(qzh[i]>=q)
            return i;
}

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        qzh[i]=a[i]+qzh[i-1];
    }
    int m=qzh[n]/2,ans=0;
    for(int i=1;i<=m;i++)
    {
        int x=f(i),y=f(qzh[n]+1-i);
        if(c[x]!=c[y])
            ans++;
    }
    cout<<ans;
    return 0;
}
