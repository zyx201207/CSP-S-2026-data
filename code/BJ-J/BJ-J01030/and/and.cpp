#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200001];
char c[200001];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    int cur=log2(a[1]);
    int ans=0;
    while(cur>=0)
    {
        int cnt=0;
        int zzy=(1<<cur);
        if(a[m]<zzy)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]>=zzy)a[i]-=zzy;
            }
            sort(a+1,a+n+1,greater<int>());
        }
        else
        {
            ans+=zzy;
            for(int i=1;i<=n;i++)
            {
                if(i<=m)a[i]-=zzy;
                else a[i]=0;
            }
            sort(a+1,a+n+1,greater<int>());
        }
        cur--;
    }
    cout<<ans;
    return 0;
}
/*
4 3
8 6 3 3
*/
