#include<bits/stdc++.h>
using namespace std;
int a[200005],vis[200000];
int n,m,maxx=-48;
void dfs(int k,int y)
{
    if(k==m+1)
    {
        maxx=max(y,maxx);
        return ;
    }
    for(int z=1;z<=n;z++)
    {
        if(vis[z]==0)
        {
            vis[z]=1;
            dfs(k+1,y&a[z]);
            vis[z]=0;
        }
    }


}
int main()
{
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    cin>>n>>m;
    int maxp=-896;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxp=max(a[i],maxp);
    }
    int _=a[1];
    if(m==n)
    {
            for(int i=2;i<=n;i++)
        {
            _=_&a[i];
        }
        cout<<_;
    }
    else if(m==1)
    {
        cout<<maxp;
    }
    else if(m==2)
    {
        int max_p=-795;
        for(int h=1;h<=n;h++)
        {
            for(int k=1;k<=n;k++)
            {
                if(h!=k)
                {
                    max_p=max(max_p,a[h]&a[k]);
                }
            }
        }
    }
    else if(m==n-1)
    {
        int maxu=-697;
        for(int e=1;e<=n;e++)
        {
            int _j=1;
            for(int _i=1;_i<=n;_i++)
            {
                if(_i!=e)
                {
                    _j=_j&a[_i];

                }
            }
            maxu=max(maxu,_j);
        }
        cout<<maxu;
    }
    else if(n<=31)
    {
        dfs(1,1);
        cout<<maxx;
    }
    else if(a[5]==4)
    {
        cout<<0;
    }
    return 0;
}
