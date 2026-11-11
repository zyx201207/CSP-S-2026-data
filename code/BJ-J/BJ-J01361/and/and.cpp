#include<bits/stdc++.h>
using namespace std;
int a[200005];
int c[200005];
int n,m;
long long maxn=0;
void dfs(int step)
{
    if(step>m)
    {
        long long sum=a[c[1]];
        for(int i=2;i<step;i++)
        {
            sum=(sum&a[c[i]]);
        }
        maxn=max(maxn,sum);
        return;
    }
    for(int i=c[step-1]+1;i<=n;i++)
    {
        c[step]=i;
        dfs(step+1);
    }
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        maxn=0;
        for(int i=1;i<=n;i++)
        {
            maxn=max(maxn,1ll*a[i]);
        }
        cout<<maxn<<endl;
    }
    else if(m==n)
    {
        long long sum=a[1];
        for(int i=2;i<=n;i++)
        {
            sum=(a[i]&sum);
        }
        cout<<sum<<endl;
    }
    else if(m==2)
    {
        maxn=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxn=max(maxn,1ll*(a[i]&a[j]));
            }
        }
        cout<<maxn<<endl;
    }
    else if(n<=20)
    {
        c[0]=0;
        dfs(1);
        cout<<maxn<<endl;
    }
    else 
    {
        sort(a+1,a+1+n,greater<int>());
        cout<<a[m]<<endl;
    }
    return 0;
}