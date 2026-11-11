// GZ-J00207 遵义市第四中学 温岳城

#include<bits/stdc++.h>
using namespace std;

constexpr int N=200005;
int a[N],maxn=INT_MIN;
int main()
{
    // 25pts
    freopen("and.in","r",stdin);freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1)
    {
        int maxn=INT_MIN;
        for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
        cout<<maxn;return 0;
    }
    if(m==n)
    {
        int sum=0;
        for(int i=1;i<=n;i++) sum=sum&a[i];
        cout<<sum;return 0;
    }
    if(m==2)
    {
        int maxn=INT_MIN;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
            maxn=max(maxn,a[i]&a[j]);
        cout<<maxn;return 0;
    }
    return 0;
}
