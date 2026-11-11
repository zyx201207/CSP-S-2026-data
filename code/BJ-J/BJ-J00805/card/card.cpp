#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt[N],is[N],x[N],lst[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int r=0;
        for(int j=1;j<=n;j++)
            x[j]=0,lst[j]=0,is[j]=0;
        for(int j=i;j<=n;j++)
        {
            if(lst[a[j]]>r) lst[a[j]]=0;
            if(!lst[a[j]]) lst[a[j]]=++r,x[r]=a[j];
            else r=lst[a[j]]-1,lst[a[j]]=++r,x[r]=a[j];
        }
        for(int j=1;j<=r;j++)
            is[x[j]]=1;
        for(int j=1;j<=m;j++)
            cnt[j]+=is[j];
    }
    for(int i=1;i<=m;i++)
        cout<<cnt[i]<<' ';
    return 0;
}
