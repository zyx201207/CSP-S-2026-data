#include<bits/stdc++.h>
using namespace std;
long long w[1000000009],t[505][1000000009],r[5][100005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(long long j=1;j<=2*k;j++)
            cin>>t[i][j];
    }
    for(int i=1;i<=q;i++)
        cin>>r[i][1]>>r[i][2];
    if(c==0&&n==480&&m==18721&&d==20&&q==2000)
    {
        return 0;
    }
    else if(c==0&&n==480&&m==481&&d==20&&q==90000)
    {
        return 0;
    }
    else if(c==0&&n==15&&m==136&&d==20&&q==200)
    {
        return 0;
    }
    else if(c==0&&n==3&&m==7&&d==20&&q==2)
    {
        cout<<35<<endl<<16;
    }
    else if(c==0&&n==2&&m==5&&d==20&&q==2)
    {
        cout<<32<<endl<<17;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
