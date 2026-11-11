#include <bits/stdc++.h>
using namespace std;
int num[500005],ton[300005],pos[300005],sum[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>num[i];
        pos[num[i]] = i;
    }
    for(int i = 1;i<=n;i++)
    {
        int l = i;
        while(l<=n)
        {
            l = pos[num[l]];
            sum[num[l]]++;
            l++;
        }
    }
    for(int i = 1;i<=m;i++)
    {
        cout<<sum[i]<<" ";
    }
    return 0;
}
