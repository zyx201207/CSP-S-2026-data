#include<bits/stdc++.h>
using namespace std;
int n,m;
unsigned int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        int y=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>y)
            {
                y=a[i];
            }
        }
        cout<<y;
        return 0;
    }
    unsigned int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            unsigned int maxn=a[i];
            for(int z=1;z<=m;z++)
            {
                maxn=maxn&a[j];
            }
            if(maxn>ans)
            {
                ans=maxn;
            }
        }
    }
    cout<<ans;
    return 0;

}
