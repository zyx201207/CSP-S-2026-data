#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500001],b[500001],box[500001],ans[500001];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int cur=0;
    for(int i=1;i<=n;i++)
    {
        cur=0;
        for(int j=1;j<=m;j++)box[j]=0;
        for(int j=i;j<=n;j++)
        {
            if(box[a[j]]==1)
            {
                for(int k=cur;b[k]!=a[j];k--)
                    cur--,box[b[k]]--;
                cur--;
                box[a[j]]--;
            }
            box[a[j]]++;
           b[++cur]=a[j];
        }
        for(int j=1;j<=cur;j++)
        {
            ans[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    return 0;
}

