#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum,maxx=-1;
void dfs(int step,int s)
{
    if(step==m)
    {
        maxx=max(maxx,sum);
        return ;
    }
    for(int i=s+1;i<=n;i++)
    {
        int t=sum;
        if(step==0)
            sum=a[i];
        else sum&=a[i];
        dfs(step+1,i);
        sum=t;
    }
    return ;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==1)sum=a[i];
        else sum&=a[i];
        maxx=max(maxx,a[i]);
    }
    if(m==n)
    {
        cout<<sum;
        return 0;
    }
    if(m==1)
    {
        cout<<maxx;
        return 0;
    }
    sum=0;
    maxx=-1;
    dfs(0,0);
    cout<<maxx;
    return 0;
}
