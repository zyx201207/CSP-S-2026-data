#include<iostream>
#include<vector>
using namespace std;
int c,n,m,d,q,w[1000010],P,uu,vv;
long long dk[510][510];
vector<int>gz[500010];
vector<long long>gt[500010];
inline long long read()
{
    long long x=0;
    char ch;
    ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while('0'<=ch&&ch<='9')
        x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return x;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        w[i]=read();
    for(int i=1;i<=n;i++)
    {
        P=read();
        for(int j=0;j<=n;j++)
            dk[i][j]=1e17+10;
        dk[i][i]=0;
        for(int j=1;j<=P;j++)
        {
            int zt,tm;
            zt=read();
            tm=read();
            gz[zt].push_back(i);
            gt[zt].push_back(tm);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<gz[i].size();j++)
            for(int k=0;k<gz[i].size();k++)
        if(gz[i][j]!=gz[i][k])
        dk[gz[i][j]][gz[i][k]]=min(dk[gz[i][j]][gz[i][k]],gt[i][j]+gt[i][k]);
    }
    for(int k=1;k<=n;k++)
       for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(i!=j&&j!=k&&i!=k)
                    dk[j][i]=dk[i][j]=min(dk[i][j],dk[i][k]+dk[k][j]);

    while(q--)
    {
        long long ans=1e17;
        uu=read();
        vv=read();
        for(int i=0;i<gz[uu].size();i++)
            for(int j=0;j<gz[vv].size();j++)
               ans=min(ans,dk[gz[uu][i]][gz[vv][j]]+gt[uu][i]+gt[vv][j]);
        cout<<ans+w[uu]+w[vv]<<endl;
    }
    return 0;
}
