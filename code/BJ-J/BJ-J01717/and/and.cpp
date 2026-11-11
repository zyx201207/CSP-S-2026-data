#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],vis[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int f=0;
    for(int i=30;i>=0;i--)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(((a[j]>>i)&1)==1&&(f==0||(f==1&&vis[j]==1)))
            {
                cnt++;
            }
        }
        if(cnt>=m)
        {
           // cout<<"haha"<<i<<cnt<<f;
            if(f==1)
            {
                for(int j=1;j<=n;j++)
                {
                    if(vis[j]==1)
                    {
                        if((a[j]>>i)&1==1) vis[j]==1;
                        else vis[j]=0;
                    }
                }
            }
            else
            {
                for(int j=1;j<=n;j++)
                {
                    if((a[j]>>i)&1==1)
                    {
                        vis[j]=1;
                    }
                }
                f=1;
            }
        }
    }
    int ans=(1<<31)-1,p=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==1){
            ans&=a[i];
           // cout<<a[i];
            p++;
        }
    }
    if(p!=0) cout<<ans;
    else cout<<0;
    return 0;
}
