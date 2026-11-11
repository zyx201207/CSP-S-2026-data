#include<bits/stdc++.h>
using namespace std;
int ans[300010],a[500010],b[500010],b1=0,v[500010],f=1;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(v[a[i]]==1)
        {
            f=0;
        }
        v[a[i]]=1;
    }
    if(f==1)
    {
        for(int i=0;i<n;i++)
        {
            cout<<i+1<<' ';
        }
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            b[b1]=a[j];
            for(int q=0;q<b1;q++)
            {
                if(b[q]==b[b1])
                {
                    for(int w=q;w<b1;w++)
                    {
                        b[w]=-1;
                    }
                    break;
                }
            }
            b1++;
        }
        for(int j=0;j<b1;j++)
        {
            if(b[j]!=-1)
            {
                ans[b[j]]++;
            }
        }
        b1=0;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
