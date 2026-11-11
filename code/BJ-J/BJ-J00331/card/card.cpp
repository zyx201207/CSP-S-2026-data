#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300005];
bool b[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i=i+1)
    {
        cin>>a[i];
    }
    for(int i=2;i<=n+1;i=i+1)
    {
        for(int j=i-1;j<=n;j=j+1)
        {
            if(b[a[j]])
            {
                for(int k=1;k<=m;k=k+1)
                {
                    b[k]=0;
                }
            }
            b[a[j]]=1;
        }
        for(int j=1;j<=m;j++)
        {
            if(b[j])
            {
                ans[i]++;
            }
        }
    }
    for(int j=1;j<=m;j++)
    {
        cout<<ans[j]<<" ";
    }
    return 0;
}