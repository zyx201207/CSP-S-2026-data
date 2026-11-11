#include<bits/stdc++.h>
using namespace std;
const long long MX=5e5+10,MXX=3e5+10;
long long n,m,a[MX],d[MXX];
bool bj[MX];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool mk=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1])
        {
            mk=1;
        }
    }
    if(mk==0)
    {
        for(int i=1;i<=n;i++)
        {
            memset(bj,1,sizeof(bj));
            for(int j=i+1;j<=n;j++)
            {
                if(a[j-1]==a[j])
                {
                    bj[j-1]=0;
                }
            }
            for(int j=i;j<=n;j++)
            {
                if(bj[j])
                {
                    d[a[j]]++;
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            cout<<d[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        vector<long long> c;
        for(int j=i;j<=n;j++)
        {
            for(int k=0;k<c.size();k++)
            {
                if(c[k]==a[j])
                {
                    for(int p=k;p<=c.size();p++)
                    {
                        c[p]=0;
                    }
                }
            }
            c.push_back(a[j]);
        }
        for(int i=0;i<c.size();i++)
        {
            d[c[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<d[i]<<" ";
    }
    return 0;
}
