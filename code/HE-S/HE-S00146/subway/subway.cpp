#include <bits/stdc++.h>
using namespace std;
struct At
{
    int z;
    int t;
};
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,time=0;
    int w[10001],k[10001],s[10001],e[10001];
    At a[10001];
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>k[i];
        for(int j=0;j<k[i];j++)
        {
            cin>>a[j].z>>a[j].t;
        }
    }
    for(int i=0;i<q;i++)
    {
        cin>>s[i]>>e[i];
    }
    for(int i=0;i<q;i++)
    {
        time+=w[s[i]];
        time+=a[s[i]].t;
        for(int i=0;i<n;i++)
        {

        }
    }
    return 0;
}
