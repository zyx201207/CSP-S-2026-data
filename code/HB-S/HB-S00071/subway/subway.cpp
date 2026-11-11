#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define dd double
#define ull unsigned long long
#define pq priority_queue
#define vec vector
using namespace std;
const string PUO="subway";
const int LINEMAXN=501;
const int STATIONMAXN=5e5+5;
struct station
{
    int lengtostation;
    int cnt=0;
    int rec[LINEMAXN];
    vector<int> linenum;
}station_set[STATIONMAXN];
vector<int> line_map[LINEMAXN];
int c,n,m,d,q;
ll ans=LONG_MAX;
void bfs(int start,int point,ll now_ans,int now_station,int now_line,bool if_change_line,bool lr)
{
    if(now_station==point)
    {
        ans=min(ans,now_ans+station_set[now_station].rec[now_line]+station_set[now_station].lengtostation);
        return;
    }
    if(now_ans>ans)
    {
        return;
    }
    for(int i=0;i<station_set[now_station].cnt&&!if_change_line;i++)
    {
        if(station_set[now_station].linenum[i]==now_line)
        {
            continue;
        }
        bfs(start,point,now_ans+station_set[now_station].rec[now_line]
            +station_set[now_station].rec[station_set[now_station].linenum[i]],
            now_station,
            station_set[now_station].linenum[i],1,0);
        bfs(start,point,now_ans+station_set[now_station].rec[now_line]
            +station_set[now_station].rec[station_set[now_station].linenum[i]],
            now_station,
            station_set[now_station].linenum[i],1,1);
    }
    int a;
    for(int i=0;i<line_map[now_line].size();i++)
    {
        if(line_map[now_line][i]==now_station)
        {
            a=i;
            break;
        }
    }
    if(a!=0&&lr)
    {
        bfs(start,point,now_ans,line_map[now_line][a-1],now_line,0,0);
    }
    if(a!=line_map[now_line].size()-1&&lr)
    {
        bfs(start,point,now_ans,line_map[now_line][a+1],now_line,0,1);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef cspjudge
    string filename_in=PUO+".in";
    string filename_out=PUO+".out";
    freopen(filename_in.c_str(),"r",stdin);
    freopen(filename_out.c_str(),"w",stdout);
    #endif
    cin>>c>>n>>m>>d>>q;
    int a;
    for(int i=1;i<=m;i++)
    {
        cin>>a;
        station_set[i].lengtostation=a;
    }
    int b,c;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        while(a--)
        {
            cin>>b>>c;
            station_set[b].rec[b]=c;
            line_map[a].push_back(b);
            station_set[b].linenum.push_back(i);
            station_set[b].cnt++;
        }
    }
    while(q--)
    {
        ans=0;
        cin>>a>>b;
        for(int i=0;i<station_set[a].cnt;i++)
        {
            bfs(a,b,(ll)(station_set[a].lengtostation+station_set[a].rec[station_set[a].linenum[i]]),a,station_set[a].linenum[i],0,0);
            bfs(a,b,(ll)(station_set[a].lengtostation+station_set[a].rec[station_set[a].linenum[i]]),a,station_set[a].linenum[i],0,1);
        }
        cout<<ans<<endl;
    }
    return 0;
}

