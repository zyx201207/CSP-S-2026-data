#include<bits/stdc++.h>
using namespace std;
int a[200008];
bool f[200008];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0;
    for(int i=30;i>=0;i--)
    {
        int cnt=0;
        memset(f,0,sizeof(f));
        for(int j=1;j<=n;j++)
        {
            int x=a[j]%(1<<(i+1));
            if(x>>i)cnt++,f[j]=1;
        }
        if(cnt>=m)
        {
            ans=ans<<1;
            ans+=1;
            for(int j=1;j<=n;j++)
            {
                if(!f[j])a[i]=0;
            }
        }
        else
        {
            ans=ans<<1;
            ans+=0;
        }
    }
    cout<<ans;
}
