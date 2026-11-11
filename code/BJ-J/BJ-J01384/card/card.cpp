#include<bits/stdc++.h>
using namespace std;
int n,m;
int h[300005];
int a[500005];
int ans[300005];
int h2[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=i;j<=n;j++)
        {
            if(h[a[j]]&&cnt>=h[a[j]]&&h2[h[a[j]]]==a[j])
            {
                cnt=h[a[j]];
            }
            else
            {
                h[a[j]]=++cnt;
                h2[cnt]=a[j];
            }
        }
        for(int j=1;j<=cnt;j++)ans[h2[j]]++;
        memset(h,0,sizeof(h));
        memset(h2,0,sizeof(h2));
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}

