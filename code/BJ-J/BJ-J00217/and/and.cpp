#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ans=-1e9;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i,j,k,l,x,y,z;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    if (m==1)
        cout<<*max_element(a+1,a+n+1);
    else if (m==2)
    {
        for (i=1;i<=n;i++)
            for (j=i+1;j<=n;j++)
                if (a[i]>ans||a[j]>ans)
                    ans=max(ans,a[i]&a[j]);
        cout<<ans<<endl;
    }
    else if (m==3)
    {
        for (i=1;i<=n-2;i++)
            for (j=i+1;j<=n-1;j++)
                for (k=j+1;k<=n;k++)
                    if (a[i]>ans||a[j]>ans||a[k]>ans)
                        ans=max(ans,a[i]&a[j]&a[k]);
        cout<<ans<<endl;
    }
    else if (m==4)
    {
        for (i=1;i<=n-3;i++)
            for (j=i+1;j<=n-2;j++)
                for (k=j+1;k<=n-1;k++)
                    for (l=k+1;l<=n;l++)
                    if (a[i]>ans||a[j]>ans||a[k]>ans||a[l]>ans)
                        ans=max(ans,a[i]&a[j]&a[k]&a[l]);
        cout<<ans<<endl;
    }
    else if (m==5)
    {
        for (i=1;i<=n-4;i++)
        for (j=i+1;j<=n-3;j++)
        for (k=j+1;k<=n-2;k++)
        for (l=k+1;l<=n-1;l++)
        for (x=l+1;x<=n;x++)
        if (a[i]>ans||a[j]>ans||a[k]>ans||a[l]>ans||a[x]>ans)
        ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[x]);
        cout<<ans<<endl;
    }
    else if (m==6)
    {
        for (i=1;i<=n-5;i++)
        for (j=i+1;j<=n-4;j++)
        for (k=j+1;k<=n-3;k++)
        for (l=k+1;l<=n-2;l++)
        for (x=l+1;x<=n-1;x++)
        for (y=x+1;y<=n;y++)
        if (a[i]>ans||a[j]>ans||a[k]>ans||a[l]>ans||a[x]>ans||a[y]>ans)
        ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[x]&a[y]);
        cout<<ans<<endl;
    }
    else if (m==7)
    {
        for (i=1;i<=n-6;i++)
        for (j=i+1;j<=n-5;j++)
        for (k=j+1;k<=n-4;k++)
        for (l=k+1;l<=n-3;l++)
        for (x=l+1;x<=n-2;x++)
        for (y=x+1;y<=n-1;y++)
        for (z=y+1;z<=n;z++)
        if (a[i]>ans||a[j]>ans||a[k]>ans||a[l]>ans||a[x]>ans||a[y]>ans||a[z]>ans)
        ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[x]&a[y]&a[z]);
        cout<<ans<<endl;
    }
    else
    {
        ans=a[1];
        for (i=2;i<=m;i++)
            ans&=a[i];
        cout<<ans<<endl;
    }
}
