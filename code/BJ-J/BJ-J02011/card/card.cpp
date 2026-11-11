#include<bits/stdc++.h>
using namespace std;
int a[200010],cnt[200010];
int n,m;
int same(int x)
{
    int ans=0;
    for(int i=1;i<x;i++)
        for(int j=n;j>x;j--)
            if(a[i]==a[j]) ans++;
    return ans;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    bool spe=true;
    for(int i=1;i<=n;i++)
        if(!(a[i]>=a[i-1]))
        {
            spe=false;
            break;
        }
    for(int i=1;i<=n;i++)
        cnt[a[i]]=i;
    if(spe==true)
    {
        for(int i=1;i<=m;i++)
            cout<<cnt[i]<<" ";
        cout<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        cnt[a[i]]-=same(i);
    for(int i=1;i<=m;i++)
        cout<<cnt[i]<<" ";
    cout<<endl;
    return 0;
}