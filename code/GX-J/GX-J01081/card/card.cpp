#include<bits/stdc++.h>
using namespace std;
long long c[300001],cnt[300001],bj[300001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    vector<long long> v;
    for(int i=1;i<=n;i++)
    {
        v.clear();
        memset(bj,0,sizeof(bj));
        for(int j=i;j<=n;j++)
        {
            if(bj[c[j]]==1)
            {
                v.clear();
                memset(bj,0,sizeof(bj));
            }
            bj[c[j]]++;
            v.push_back(c[j]);
        }
        for(int j=0;j<v.size();j++)
        {
            cnt[v[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<' ';
    }
    return 0;
}
