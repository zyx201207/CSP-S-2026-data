#include<bits/stdc++.h>
using namespace std;
//the subway lines will be treated as nodes
//since I don't know how to do floyd, I will just run a couple Dijkstra's
typedef long long ll;
const ll MAXM=505;
const ll MAXN=5e5+5;
ll end_dis[MAXM];
struct node
{
    vector<ll> nei,dis;//neighboring node index, distance to that node
} nodes[MAXN+MAXM];
struct dijk
{
    ll index, dis;
    bool operator<(const dijk other) const
    {
        return dis>other.dis;
    }
};
//nodes[1--n] is for stations, nodes[n+1--n+m] is for lines
int main()
{
    ios::sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c,n,m,d,q;//subway lines num, stations num, max num of stations per line, queries num
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++)
    {

        cin>>end_dis[i];
    }
    //cout<<"a"<<flush;
    for(int i=1;i<=m;i++)
    {
        int con;
        cin>>con;
        for(int j=1;j<=con;j++)
        {
            int tn,td;
            cin>>tn>>td;
            nodes[n+i].nei.push_back(tn);
            nodes[n+i].dis.push_back(td);
            nodes[tn].nei.push_back(n+i);
            nodes[tn].dis.push_back(td);
        }
    }
    //cout<<"b"<<flush;
    for(int i=1;i<=n+m;i++)
    {
        /*for(int j=0;j<nodes[i].nei.size();j++)
        cout<<nodes[i].nei[j]<<" "<<nodes[i].dis[j]<<"\t";*/
        //cout<<"\n";
    }
    //cout<<"c"<<flush;
    pair<int,int> rec[q+1];
    ll ans[q+1];
    for(int i=1;i<=q;i++)
    {
        ll from, to;
        cin>>from>>to;
        if(from>to)swap(from,to);
        bool been[n+m+5]={0};//if it had been visited
        priority_queue<dijk> visit;
        visit.push({from,0});
        while(true)
        {

            ll ci=visit.top().index;//current index
            ll cd=visit.top().dis;//current distance from start
            visit.pop();
            //cout<<"d"<<flush;
            //cout<<ci<<" "<<cd<<"\t";
            if(ci==to)
            {
                //give answer; the destination has been arrived
                cout<<cd+end_dis[to]+end_dis[from]<<"\n";
                rec[i]={from,to};
                ans[i]=cd+end_dis[to]+end_dis[from];
                break;
            }
            if(been[ci])
            {
                continue;
            }
            been[ci]=1;
            for(ll j=0;j<nodes[ci].nei.size();j++)
            {
                //cout<<nodes[ci].nei[j]<<" ";
                visit.push({nodes[ci].nei[j],cd+nodes[ci].dis[j]});
            }
            //cout<<"\n";
        }
    }
}
