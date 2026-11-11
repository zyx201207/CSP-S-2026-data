#include<bits/stdc++.h>
using namespace std;
int a[500010];
int h[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>1&&a[i]>=a[i-1]) cnt++;
    }
    for(int i=1;i<=n;i++)//ju
    {
        vector<int> v;
        for(int j=i;j<=n;j++)
        {
            v.push_back(a[j]);
        }
        for(int j=i;j<=n;j++)//da chu
        {
            int k;
            bool flag=0;
            for(int k=0;k<v.size();k++)
            {
                if(a[j]==v[k]) flag=1;
                if(flag) v.pop_back();
            }
            v.push_back(a[j]);
        }
        for(int j=0;j<v.size();j++)
        {
            cout<<v[j]<<" ";
            h[v[j]]++;
        }
        cout<<"\n";
    }
    if(cnt==n-1)
    {
        for(int i=1;i<=n+1;i++)
        {
            if(a[i]!=a[i-1]&&i>1) cout<<i-1<<" ";
        }
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<h[i]<<" ";
    }
    return 0;
}
