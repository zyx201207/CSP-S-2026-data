#include<bits/stdc++.h>
using namespace std;
long long int read()
{
    long long int x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return x;
}
bool vis[200001][31],flag[200001];
int n,m;
long long base[31];
int main()
{
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
    n=read();
    m=read();
    base[0]=1;
    for(int i=1;i<=30;i++) base[i]=base[i-1]*2;
    for(int i=1;i<=n;i++)
    {
        long long x=read();
        for(int j=30;j>=0;j--)
        {
            if(base[j]<=x)
            {
                x-=base[j];
                vis[i][j]=1;
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++) flag[i]=1;
    for(int j=30;j>=0;j--)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(!flag[i]) continue;
            if(vis[i][j]) cnt++;
        }
        if(cnt>=m)
        {
            ans|=(1ll<<j);
            for(int i=1;i<=n;i++) if(!vis[i][j]) flag[i]=0;
        }
    }
    cout<<ans;
    return 0;
}
