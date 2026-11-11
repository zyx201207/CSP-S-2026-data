#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
const int maxl=35;
int a[maxn];
int c[maxn][maxl];
int cnt[maxl];
int s[maxn];
int lowbit(int x)
{
    return x&(-x);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int x=a[i];
        while(x)
        {
            int w=__builtin_ctz(x)+1;
            c[i][w]=1;
            cnt[w]++;
            x-=lowbit(x);
        }
    }
    for(int i=32;i>=1;i--)
    {
        if(cnt[i]>=m)
        {
            for(int j=1;j<=n;j++)
            {
                if(c[j][i])
                {
                    s[j]=s[j]*2+1;
                }
                else
                {
                    s[j]=s[j]*2;
                }
            }
        }
        else
        {
            for(int j=1;j<=n;j++)
            {
                s[j]*=2;
            }
        }
    }
    sort(s+1,s+n+1,greater<int>());
    int ans=s[1];
    for(int i=2;i<=m;i++)
    {
        ans=ans&s[i];
    }
    cout<<ans;
    return 0;
}
