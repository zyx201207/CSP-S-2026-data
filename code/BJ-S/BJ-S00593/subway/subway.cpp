#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[500005],train[505],platfromtime[505],start[100005],endstation[100005];
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        for(int j=1;j<=t;j++)
        {
            cin>>train[i]>>platfromtime[i];
        }
    }
    for(int i=1;i<=q;i++)
    {

        cin>>start[i]>>endstation[i];

    }
    return 0;
}
