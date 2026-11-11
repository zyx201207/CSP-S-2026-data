#include <bits/stdc++.h>
using namespace std;

const long long NN=505, MM=5e5+5;
long long c,n,m,d,q;
long long tmp1,tmp2,tmp3;
long long mint[NN][NN], minl[NN][NN];
bool vis[NN];

struct astation
{
    long long tw, cnt;
    vector<pair<long long,long long>> sl;
}sts[MM];

void dij(long long u)
{
    for (long long i = 0; i < n; i++)
        vis[i]=0;

    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    pq.push({0,u});
    while (!pq.empty())
    {
        pair<long long,long long> e=pq.top();
        pq.pop();
        if(vis[e.second]==true)
            continue;
        vis[e.second]=1;
        minl[u][e.second]=e.first;
        for (long long i = 0; i < n; i++)
        {
            if(mint[e.second][i]!=2e9+7 && !vis[i])
                pq.push({mint[e.second][i]+minl[u][e.second],i});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(long long i=0;i<m;i++)
        cin>>sts[i].tw;

    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
            mint[i][j]=2e9+7,minl[i][j]=0;
    }
    
    for (long long i = 0; i < n; i++)
    {
        cin>>c;
        for (long long j = 0; j < c; j++)
        {
            cin>>tmp1>>tmp2;
            tmp1-=1;
            sts[tmp1].sl.push_back({i,tmp2});
            sts[tmp1].cnt++;
            for(long long z=0;z<sts[tmp1].cnt-1LL;z++)
            {
                long long q1=sts[tmp1].sl[z].first, q2=sts[tmp1].sl[z].second;
                mint[q1][i]=min(mint[q1][i],tmp2+q2);
                mint[i][q1]=min(mint[i][q1],tmp2+q2);
            }
        }
    }

    for (long long i = 0; i < n; i++)
        dij(i);
    
    for (long long i = 0; i < q; i++)
    {
        cin>>tmp1>>tmp2;
        tmp1-=1,tmp2-=1;
        long long suma=sts[tmp1].tw+sts[tmp2].tw, mie=2e13+7;
        for (long long i = 0; i < sts[tmp1].cnt; i++)
        {
            for (long long j = 0; j < sts[tmp2].cnt; j++)
            {
                long long tmp4= sts[tmp1].sl[i].second + sts[tmp2].sl[j].second +
                                minl[sts[tmp1].sl[i].first][sts[tmp2].sl[j].first];
                if(tmp4<mie) 
                    mie=tmp4;
            }
        }
        cout<<suma + mie<<endl;
    }

    return 0;
}