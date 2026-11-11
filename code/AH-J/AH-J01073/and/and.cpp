#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N][31],m,c[N],tot,mx;
long long ans;
signed main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        int cnt=0;
        while(x)
        {
            if(x&1)a[i][cnt]=1;
            cnt++,x>>=1;
        }
    }
    for(int k=30;k>=0;k--)
    {
        int sum=0;
        for(int j=1;j<=n;j++)
            sum+=a[j][k];
        if(sum>=m)
        {
            mx=k,ans=1<<k;
            for(int i=1;i<=n;i++)
                if(a[i][k])c[++tot]=i;
            break;
        }
    }
    if(tot==0)
    {
        cout<<0;
        return 0;
    }
    for(int i=mx-1;i>=0;i--)
    {
        int sum=0;
        for(int j=1;j<=tot;j++)
            sum+=a[c[j]][i];
        if(sum>=m)
        {
            int x=0;
            for(int j=1;j<=tot;j++)
                if(a[c[j]][i])c[++x]=c[j];
            tot=x,ans+=1<<i;
        }
    }
    cout<<ans;
    return 0;
}
