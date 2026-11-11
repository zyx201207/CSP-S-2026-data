#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
关注592080谢谢喵！

预计100+100+56+15=271pts

14:50 读题
14:51 吃猪肉脯，零食-1，目前余3
14:53 大概会了，开写
14:53 不会了，重读
14:54 什么叫5e5个点求全源最短路？？？

猪思考：
1.不换乘一定比换乘更优
2.两线换乘只取最快的站，也就是最多500个点

会了，floyd即可

15:07 写完了
15:08 没过，开调
15:11 改对了，不会写拍子，goto->migrate
*/

void solve()
{
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;

    vector<int> a(m+1);
    for (int i=1;i<=m;i++)
        cin>>a[i];
    
    vector<int> k(n+1);
    vector<vector<int>> pos(n+1),v(n+1),dis(n+1,vector<int>(n+1,0x3f3f3f3f3f3f3f3f));
    vector<vector<pair<int,int>>> val(m+1);
    for (int i=1;i<=n;i++)
    {
        cin>>k[i];
        pos[i].resize(k[i]+1);
        v[i].resize(k[i]+1);
        for (int j=1;j<=k[i];j++)
        {
            cin>>pos[i][j]>>v[i][j];

            for (auto tmp:val[pos[i][j]])
            {
                dis[i][tmp.first]=min(dis[i][tmp.first],v[i][j]+tmp.second);
                dis[tmp.first][i]=dis[i][tmp.first];
            }
            val[pos[i][j]].emplace_back(i,v[i][j]);
        }
    }

    for (int i=1;i<=n;i++)
        for (int k=1;k<=n;k++)
            for (int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    
    while (q--)
    {
        int x,y;
        cin>>x>>y;

        vector<int> getx,gety;

        int ans=0x3f3f3f3f3f3f3f3f;
        for (auto i:val[x])
            for (auto j:val[y])
                ans=min(ans,a[x]+a[y]+(i.first!=j.first)*dis[i.first][j.first]+i.second+j.second);
        cout<<ans<<'\n';
    }
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2 
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

signed main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifndef LOCAL
        freopen("subway.in","r",stdin);
        freopen("subway.out","w",stdout);
    #endif

    int T=1;
    // cin>>T;

    while (T--)
    {
        solve();
        if (T)
            cout<<'\n';
    }
    return 0;
}