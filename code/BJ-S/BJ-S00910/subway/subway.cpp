#include<iostream>
#include<vector>
using namespace std;
int c,n,m,d,q,b[500001];
struct sub
{
    vector<int> zd;
    vector<int> time;
}a[501];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        int tmp;cin>>tmp;
        for(int i=1;i<=tmp;i++)
        {
            int tmpp,tmmp;cin>>tmpp>>tmmp;
            a[n].zd.push_back(tmpp);
            a[n].time.push_back(tmmp);
        }

    }
    for(int i=1;i<=q;i++)
    {
        int st,en;
        long long ans=0;
        cin>>st>>en;
        ans+=b[st]+b[en];

    }
    return 0;
}
