#include<bits/stdc++.h>
using namespace std;
const int M=5e5+4;
const int N=5e2+4;
int sd[N][10000];
int t[N][10000];
int w[M],k[N];
void dfs(int x,int y)
{

}
int main()
{
    //我的妈呀看题看了一个小时 还没看懂
    //这题真神了 服了 不做了
    //555 出题人我APT
    //has ice ba
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,s,b;
    cin>>c>>n>>m>>s>>b;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>sd[i][j]>>t[i][j];
        }
    }
    while(b--)
    {
        int x,y;
        cin>>x>>y;
        dfs(x,y);
    }
    return 0;
}