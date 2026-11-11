#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int b[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,maxn=0;
    cin>>n>>m;
    for(int i=0,x;i<n;++i)
    {
        cin>>x;
        maxn=max(maxn,x);
        v.push_back(x);
    }int flag=0;
    for(int i=0;i<n-1;++i)
    {
        if(v[i]>v[i+1])
        {
            flag=1;
            break;
        }
    }
    if(flag)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=i;j<n;++j)
            {

                int idx=-1;
                for(int k=n-1;k>j;--k)
                {
                    if(v[k]==v[j])
                    {
                        idx=k;
                        break;
                    }
                }
                if(idx>0)
                {
                    b[v[j]]++;
                    j=idx;
                }
                else
                {
                    b[v[j]]++;
                }
            }
        }
        for(int i=1;i<=maxn;++i)
        {
            if(b[i]>=0) cout<<b[i]<<' ';
        }
    }
    else {
        for(int i=1;i<=m;++i)
        {
            cout<<i<<' ';
        }
    }
    return 0;
}

