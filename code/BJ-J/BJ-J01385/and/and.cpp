#include <bits/stdc++.h>
using namespace std;
long long n,m,b[200001]={},maxn=0,dm[200001]={};
bool a[200001]={};
void s(long long u)
{
    if (u==m)
    {
        long long qm=dm[0];
        for (int i=1;i<m;i++)
        {
            qm=qm & dm[i];
        }
        maxn=max(qm,maxn);
        return;
    }
    for (int i=0;i<n;i++)
    {
        if (!a[i])
        {
            dm[u]=b[i];
            a[i]=true;
            s(u+1);
            a[i]=false;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    s(0);
    cout<<maxn;
    return 0;
}
