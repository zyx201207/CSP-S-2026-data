#include<bits/stdc++.h>
using namespace std;
int w[200050],v[200050];
bool cmp(int x,int y)
{
    return x>y;
}
int maxn=-1e9;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        maxn=max(maxn,v[i]);
    }
    int s=v[1];
    for(int i=2;i<=n;i++)
    {
        s=(s&v[i]);
    }
    if(m==n)
    {
        cout<<s;
        return 0;
    }
    if(m==1)
    {
        cout<<maxn;
        return 0;
    }
    if(m==2)
    {
        int maxn=-1e9,rj,ri;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(i!=j && v[i]&v[j]>maxn)
                {
                    maxn=(v[i]&v[j]);
                    ri=i,rj=j;
                }
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==n-1)
    {
        int ans=0,gh=-1e9;
        for(int i=1;i<=n;i++)
        {
            int gh=-1e9;
            if(i==1) ans=v[2];
            else ans=v[1];
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                else ans=(ans&v[j]);
            }
            gh=max(gh,ans);
        }
        cout<<gh;
        return 0;
    }
    else
    {
        sort(v+1,v+n+1,cmp);
        cout<<v[m];
    }
    return 0;
}
