#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum=-1,maxk=-1;
void dfs(int k,int p,int no)
{
    if(k>n)
    {
        if(p==m)sum=max(sum,no);
        return;
    }
    if(p==m)
    {
        sum=max(sum,no);
        return;
    }
    dfs(k+1,p+1,no&a[k]);
    dfs(k+1,p,no);
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        maxk=max(maxk,a[i]);
    }
    if(m==1)
    {
        int maxn=-1;
        for(int i=1;i<=n;++i)maxn=max(maxn,a[i]);
        cout<<maxn;
        return 0;
    }
    if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;++i)
        {
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==2)
    {
        int maxn=-1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(i!=j)maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }
    if(n<=20)
    {
        dfs(1,0,pow(2,21)-1);
        cout<<sum;
        return 0;
    }
    if(maxk==3)
    {
        sort(a+1,a+n+1);
        int ans=7;
        for(int i=n;i>=n-m+1;--i)
        {
            ans=ans&a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
