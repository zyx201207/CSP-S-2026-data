#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],la[500001],dc,ans[500001];
bool os[500001],hn[500001],shn[500001];
vector <int> e[500001],oe[500001];
struct Ds
{
    int l,r;
}ds[500001];
bool cmp (Ds x,Ds y)
{
    return x.l<y.l;
}
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if (la[a[i]]!=0)
        {
            ds[++dc]={la[a[i]],i-1};
        }
        la[a[i]]=i;
    }
    sort(ds+1,ds+dc+1,cmp);
    for (int i=1;i<=dc;i++)
    {
        for (int j=ds[i].l;j<=ds[i].r;j++)
        {
            e[ds[i].l].push_back(j);
            oe[j].push_back(ds[i].l);
        }
    }
    for (int i=1;i<=n;i++)
    {
        memset(os,false,sizeof(os));
        memset(hn,true,sizeof(hn));
        memset(shn,false,sizeof(shn));
        for (int j=i;j<n;j++)
        {
            bool flag=false;
            for (auto k:oe[j])
            {
                if (os[k])
                {
                    flag=true;
                    break;
                }
            }
            if (!flag)
            {
                os[j]=true;
                for (auto k:e[j])
                {
                    hn[k]=false;
                }
            }
        }
        for (int j=i;j<=n;j++)
        {
            //cout << hn[j] << " ";
            if (!hn[j])
            {
                continue;
            }
            shn[a[j]]=true;
        }
        //cout << endl;
        for (int j=1;j<=m;j++)
        {
            if (shn[j])
            {
                ans[j]++;
            }
        }
    }
    for (int i=1;i<=m;i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
