#include<bits/stdc++.h>
using namespace std;

int a[200005];
int f[200005];
int c[200005];
int n,m;

int and1(int x,int y)
{
    int a[1000]={};
    int b[1000]={};
    for(int i=20;i>=1;i--)
    {
        if(x>=pow(2,i-1))
        {
            a[i]=1;
            x-=pow(2,i-1);
        }
    }
    for(int i=20;i>=1;i--)
    {
        if(y>=pow(2,i-1))
        {
            b[i]=1;
            y-=pow(2,i-1);
        }
    }

    int c[1000]={};
    for(int i=1;i<=25;i++)
    {
        if(a[i]==1&&b[i]==1)
        {
            c[i]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=25;i++)
    {
        ans+=c[i]*pow(2,i-1);
    }
    return ans;

}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    f[1]=a[1];
    c[1]=1;
    for(int i=2;i<=n;i++)
    {
        int t=0,maxt=0;
        for(int j=1;j<i;j++)
        {
          if(c[j]!=m)
          {
              t=j;
              maxt=max(maxt,and1(f[i],f[j]));
          }
        }
        c[i]=c[t]+1;
        f[i]=maxt+a[i];
    }

    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        if(c[i]==m)
        {
            maxn=max(maxn,f[i]);
        }
    }
    cout<<maxn;
    return 0;
}
