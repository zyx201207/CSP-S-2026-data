#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main()
{
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    //cout<<(12&12);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    if(m==n)
    {
        long long ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==2)
    {
        long long ans;
        long long maxn=-100005;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=a[i]&a[j];
                maxn=max(maxn,ans);
                //cout<<ans<<" ";
            }
        }
        cout<<maxn;
    }
    else if(m==3)
    {
        long long maxn=-100005;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=j;k<=n;k++)
                {
                    maxn=max(maxn,a[i]&a[j]&a[k]);
                }
            }
        }
        cout<<maxn;
    }
    else if(m==4)
    {
        long long maxn=-100005;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=j;i<=n;i++)
                {
                    for(int l=k;l<=n;l++)
                    {
                        maxn=max(maxn,a[i]&a[j]|a[k]&a[l]);
                    }
                }
            }
        }
        cout<<maxn;
    }
    else if(m==5)
    {
        long long maxn=-100005;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=j;i<=n;i++)
                {
                    for(int l=k;l<=n;l++)
                    {
                        for(int p=l;p<=n;p++)
                        {
                            maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[p]);
                        }
                    }
                }
            }
        }
        cout<<maxn;
    }
    else if(m==6)
    {
        long long maxn=-100005;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=j;i<=n;i++)
                {
                    for(int l=k;l<=n;l++)
                    {
                        for(int p=l;p<=n;p++)
                        {
                            for(int o=p;o<=n;o++)
                            {
                                maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[p]&a[o]);
                            }
                        }
                    }
                }
            }
        }
        cout<<maxn;
    }
    else if(m==7)
    {
        long long maxn=-100005;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=j;i<=n;i++)
                {
                    for(int l=k;l<=n;l++)
                    {
                        for(int p=l;p<=n;p++)
                        {
                            for(int o=p;o<=n;o++)
                            {
                                for(int u=o;u<=n;u++)
                                {
                                    maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[p]&a[o]&a[u]);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<maxn;
    }
    else if(m==8)
    {
        long long maxn=-100005;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=j;i<=n;i++)
                {
                    for(int l=k;l<=n;l++)
                    {
                        for(int p=l;p<=n;p++)
                        {
                            for(int o=p;o<=n;o++)
                            {
                                for(int u=o;u<=n;u++)
                                {
                                    for(int y=u;y<=n;y++)
                                    {
                                        maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[p]&a[o]&a[u]&a[y]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<maxn;
    }
    else if(m==9)
    {
        long long maxn=-100005;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=j;i<=n;i++)
                {
                    for(int l=k;l<=n;l++)
                    {
                        for(int p=l;p<=n;p++)
                        {
                            for(int o=p;o<=n;o++)
                            {
                                for(int u=o;u<=n;u++)
                                {
                                    for(int y=u;y<=n;y++)
                                    {
                                        for(int t=y;t<=n;t++)
                                        {
                                            maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[p]&a[o]&a[u]&a[y]&a[t]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<maxn;
    }
    else if(m==10)
    {
        long long maxn=-100005;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=j;i<=n;i++)
                {
                    for(int l=k;l<=n;l++)
                    {
                        for(int p=l;p<=n;p++)
                        {
                            for(int o=p;o<=n;o++)
                            {
                                for(int u=o;u<=n;u++)
                                {
                                    for(int y=u;y<=n;y++)
                                    {
                                        for(int t=y;t<=n;t++)
                                        {
                                            for(int r=t;r<=n;r++)
                                            {
                                                maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[p]&a[o]&a[u]&a[y]&a[t]&a[r]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<maxn;
    }
    return 0;
}
