#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int a[N];
char c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i]>>c[i];
    int l=1,r=n,d1=a[1],d2=a[n];
    long long ans=0;
    while (l<r)
    {
        int x=min(d1,d2);
        if (c[l]!=c[r]) ans+=x;
        d1-=x,d2-=x;
        if (d1==0) l++,d1=a[l];
        if (d2==0) r--,d2=a[r];
    }
    cout<<ans;
    return 0;
}
