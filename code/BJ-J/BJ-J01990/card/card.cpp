#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1010100],ans[1010100],nxt[1010100],cnt[1010100],lst[1010100];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[i]=1;
    }
    for(int i=n;i>=1;i--)
    {
        nxt[i]=lst[a[i]];
        lst[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(nxt[i]!=0)
        {
            cnt[nxt[i]]+=cnt[i];
        }
        else
        {
            ans[a[i]]+=cnt[i];
            cnt[i+1]+=cnt[i];
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

