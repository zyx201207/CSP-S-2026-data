#include<bits/stdc++.h>
using namespace std;
#define itn int
#define ll long long
int c,d,n,m,r;
// vector<int> g[500005];
// int d[500005]; //Dij所求最短路长
int exsta[500005]; //进站口到站台
int tjd[505][500005]; //从该地铁站的站厅走到第 i 条线路的站台所需时间(换乘时间)
int sta[505][500005]; //一条线路上的站台编号
int f[5005][5005];
map<pair<int,int>,int> id;
// priority_queue< pair<int,int> > que;
void floyd()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            for(int k=1;k<=n;k++)
            {
                if(j==k || i==k)
                    continue;
                int it=i,jt=j,kt=k;
                if(i>j)
                    swap(it,jt);
                if(jt>kt)
                    swap(jt,kt);
                if(it>kt)
                    swap(it,kt);
                f[it][jt]=min(f[it][kt]+tjd[id[{it,kt}]][2]+tjd[id[{kt,jt}]][1]+f[kt][jt],f[it][jt]);
            }
        }
    }
    return ;
}
// void Dij(int rts)
// {
//     memset(d,0x3f,sizeof(d));
//     d[rts]=0;
//     que.push({0,rts});
//     while(!que.empty())
//     {
//         int u=que.top().second,valu=que.top().first;
//         que.pop();
//         for(auto tes:g[u])
//         {
//             int v=tes.v,valv=tes.val;
//             if(d[v]>d[u]+valv)
//             {
//                 que.push({-d[v],v});
//                 d[v]=d[u]+valv;
//             }
//         }
//     }
//     return ;
// }
inline void twentylowpts()
{
    for(int i=1;i<=m;i++)
    {
        int k;
        cin>>k;
        int u,v,u_sta,v_sta;
        cin>>u>>u_sta>>v>>v_sta;
        if(u>v)
            swap(u,v),swap(u_sta,v_sta);
        id[{u,v}]=i;
        tjd[i][1]=u_sta,tjd[i][2]=v_sta;
        f[u][v]=f[v][u]=0;
    }
    floyd();
    for(int i=1;i<=r;i++)
    {
        int u,v;
        cin>>u>>v;
        cout<<f[u][v]+exsta[u]+exsta[v]<<"\n";
    }
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>m>>n>>d>>r;
	memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)
        cin>>exsta[i];
    if(c>=7 && c<=11)
        twentylowpts();
    
	return 0;
}
/*
5 7 
1 2 1949
1 3 8
1 5 114514
2 3 21474836
2 4 6
3 5 9
4 5 7
*/
