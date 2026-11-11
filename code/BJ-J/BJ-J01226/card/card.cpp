#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],l;
int ans[300010];
bool f[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=5000)
    {
        for(int t=1;t<=n;t++)
        {
            l=0;
            for(int i=1;i<=m;i++) f[i]=false;
            for(int i=t;i<=n;i++)
            {
                if(f[a[i]])
                    while(b[l]!=a[i]) f[b[l--]]=false;
                else
                    b[++l]=a[i],f[a[i]]=true;
            }
//            for(int i=1;i<=l;i++)
//                cout<<b[i]<<" ";
//            cout<<"\n";
            for(int i=1;i<=l;i++)
                ans[b[i]]++;
        }
        for(int i=1;i<=m;i++)
            cout<<ans[i]<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++)
        ans[a[i]]+=i;
    for(int i=n;i>=1;i--)
    {
        if(f[a[i]])
        {
            ans[a[i]]-=i;
            while(b[l]!=a[i])
            {
                f[b[l]]=false;
                ans[b[l--]]-=i;
            }
        }
        else
            b[++l]=a[i],f[a[i]]=true;
        for(int i=1;i<=l;i++)
            cout<<b[i]<<" ";
        cout<<"\n";
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}
