#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],h[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    vector<int> v;
    for(int i=n;i>=1;i--)
    {
        int flag=-1;
        for(int j=0;j<v.size();j++)
        {
            if(v[j]==a[i])
            {
                flag=i;
            }
        }
        if(flag!=-1)
        {
            v.erase(v.begin()+flag,v.end());
        }
        v.push_back(a[i]);
        for(int j=0;j<v.size();j++)
        {
            h[v[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<h[i]<<' ';
    }
    return 0;
}
