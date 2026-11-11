#include<bits/stdc++.h>
using namespace std;
int a[200005];bool yu[200005][35],vis[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=INT_MAX;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int t=0,q=a[i];
        while(q>0)yu[i][++t]=q%2,q/=2;
        //for(int j=1;j<=t;j++)cout<<yu[i][j];cout<<endl;
    }
    for(int i=32;i>0;i--)
    {
        int s=0;
        for(int j=1;j<=n;j++)
            if(yu[j][i]==1&&vis[j]==0)s++;
        //cout<<s<<endl;
        if(s>=m)
        {
            for(int j=1;j<=n;j++)
                if(yu[j][i]==0)
                    vis[j]=1;
        }
        //for(int k=1;k<=n;k++)if(!vis[k])cout<<a[k]<<" ";cout<<endl;
    }
    for(int i=1;i<=n;i++)if(vis[i]==0)ans&=a[i];
    cout<<ans;
    return 0;
}
