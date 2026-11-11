#include<bits/stdc++.h>
using namespace std;
int x[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1)
    {
        int maxx=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            maxx=max(maxx,a);
        }
        cout<<maxx;
    }
    else if(n==m)
    {
        int minn=10000000;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            minn=min(minn,a);
        }
        cout<<minn;
    }
    else
    {
        int maxx[100000005];
        for(int i=1;i<=m;i++)
        {
            maxx[i]=0;
            bool a=0;
            for(int j=1;j<=n;j++)
            {
                cin>>x[j];
                if(x[j]>maxx[i])
                {
                    maxx[i]=x[j];
                }
            }
            if(i=m)
            {
                cout<<maxx[i];
            }
            
        }
    }
}
