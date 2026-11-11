#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,sum,k;
int m1[1000000],n1[505][100005],t1[505][100005];
int test1(long long xx,long long yy)
{
    for(int i=1;i<=n;i++)
    {
        if(n1[i][xx]==1&&n1[i][yy]==1) return i;
    }
    return 0;
}
int way1(long long xx,long long yy,long long n2)
{
    sum+=m1[xx]+t1[n2][xx]+t1[n2][yy]+m1[yy];
    return sum;
}
int way2(long long xx,long long yy,long long n2)
{
    sum+=m1[xx];

    return sum;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>m1[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        int nn,mm;
        for(int j=1;j<=k;j++)
        {
            cin>>nn>>mm;
            n1[i][nn]=1;
            t1[i][nn]=mm;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        int n2=test1(x,y);
        if(n2) cout<<way1(x,y,n2);

        else cout<<way2(x,y,n2);
        if(i!=q) cout<<endl;
    }
    return 0;
}
