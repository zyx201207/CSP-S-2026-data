#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
const int M=3e5+5;
ll n,m,a[N],b[M],ans[M],sum=1;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        sum=1;
        memset(b,0,sizeof b);
        for(int j=i;j<=n;j++)
        {
            if(b[a[j]]>0)
            {
                for(int k=1;k<=m;k++)
                {
                    if(b[k]>b[a[j]])
                    {
                        b[k]=0;
                        sum--;
                    }
                }
            }
            else
            {
                b[a[j]]=sum++;
            }
        }
        for(int j=1;j<=m;j++)
            if(b[j]>0)
                ans[j]++;
    }
    for(int i=1;i<=m;i++)
        cout << ans[i] << " ";
    return 0;
}
