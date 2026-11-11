#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[505],a[505][500005],x[100005],y[100005];
long long w[500005],t[505][500005];
int bfs(int sd,int ed)
{
    queue<int>q;
    int num=w[sd]+w[ed]+t[ed][ed];
    //q.push(sd);
    //while(!q.empty())
    //{
    //    int f=q.front();
    //    q.pop();
    //    num+=t[ed][f];
    //    if(f==ed)
              return num;
    //    for(int i=1;i<=n;i++)
    //    {
    //        q.push(i);
    //        num+=t[ed][i];
    //    }
    //}
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int v=1;v<=m;v++)
        cin>>w[v];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
            cin>>a[i][j]>>t[i][j];
    }
    for(int r=1;r<=q;r++)
    {
        cin>>x[r]>>y[r];
        cout<<bfs(x[r],y[r]);
    }
    return 0;
}