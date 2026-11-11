#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],cnt[400000],r,t[500010],s[500010];
bitset<400000> v;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        r=0;
        for(int j=i;j<=n;j++)
        {
            if(v[a[j]])
            {
                while(r>=t[a[j]])
                {
                    v.reset(s[r]);
                    r--;
                }
            }
            v.set(a[j]);
            s[++r]=a[j];
            t[a[j]]=r;
        }
        for(int j=1;j<=m;j++)
        {
            cnt[j]+=v[j];
            v.reset(j);
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<' ';
    }
    return 0;
}
