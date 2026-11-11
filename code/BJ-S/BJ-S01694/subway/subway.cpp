#include<bits/stdc++.h>
using namespace std;
struct node
{
    int p,t;
};
const int N=505,M=5e5+5,D=25,inf=2e9;
int n,m,d,q;
vector<int>a[N];
vector<int>t[N];
int num[M];
int e[M][D];
int w[M];
int start,END;
int deep=0;
int DP(int i,int j)
{
    if(deep>10) return 0;
    deep++;
   // cout<<i<<" "<<j<<endl;
    for(int k=1;k<=num[start];k++)
    {
        //cout<<a[e[start][k]][0]<<" ";
        if(i==a[e[start][k]][0]) return 0;
    }
    //cout<<endl;
    int minn=inf;
    bool reach=0;
    /*for(int k=0;k<a[j].size();k++)
    {
        cout<<a[j][k]<<" ";
    }
    cout<<endl;*/
    for(int k=0;k<a[j].size();k++)
    {
        if(a[j][k]==i) reach=1;
        else if(!reach)
        {
            minn=min(minn,DP(a[j][k],j));
        }
    }
    if(i!=a[j][0]) minn=DP(a[j][0],j);
    for(int k=1;k<=num[i];k++)
    {
        if(e[i][k]==j) continue;
        minn=min(minn,DP(i,e[i][k])+t[e[i][k]][i]+t[j][i]);
    }
    return minn;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>n>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int point,tm;
            cin>>point>>tm;
            a[i].push_back(point);
            t[i].push_back(tm);
            num[point]++;
            e[point][num[point]]=i;
        }
    }
    while(q--)
    {
        cin>>start>>END;
        int minn=inf;
        for(int i=1;i<=num[END];i++)
        {
            minn=min(minn,DP(END,e[END][i]))+w[start]+w[END]+t[i][start]+t[i][END];
            //cout<<endl;
        }
        cout<<minn<<endl;
    }
    return 0;
}
