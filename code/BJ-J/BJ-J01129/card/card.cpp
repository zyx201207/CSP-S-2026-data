#include<bits/stdc++.h>
using namespace std;
int a[500010],now[500010],ans[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=i;j<=n;j++){
            bool flag=0;
            for(int k=1;k<=cnt;k++)
                if(now[k]==a[j])
                {
                    cnt=k-1;
                    break;
                }
            now[++cnt]=a[j];
        }
        for(int j=1;j<=cnt;j++)
            if(now[j]<=m)
                ans[now[j]]++;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}
