#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[500100],b[500100]={0};
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        static int deck[100100]={0};
        int top=0;
        for (int j=i;j<=n;j++)
            {
                for (int k=1;k<top;k++)
                    if (deck[k]==a[j])
                {
                    top=k-1;
                }
                deck[++top]=a[j];
            }
        for (int i=0;i<=top;i++)
        b[deck[i]]++;

    }
    for (int i=1;i<=m;i++)
        cout<<b[i]<<" ";
    return 0;
}
