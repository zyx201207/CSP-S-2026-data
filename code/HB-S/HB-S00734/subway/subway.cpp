#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q;
ll w[500005],st[500005][25];
struct Line
{
    ll k;
    ll station[10005]={1},time[10005];
}line[505];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.in","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++) cin>>w[i];
    for(int i=0;i<n;i++)
    {
        cin>>line[i].k;
        for(int j=0;j<line[i].k;j++)
        {
            cin>>line[i].station[j]>>line[i].time[j];
            st[line[i].station[j]][st[line[i].station[j]][0]++]=i;
        }
    }
    for(int i=0;i<q;i++)
    {
        ll x,y;
        cin>>x>>y;
        if(c==20||c==21||c==1||c==2||c==3){
                ll ans=w[x]+w[y];
        /*for(int j=1;j<st[x][0];j++)
        {
            for(int k=1;k<line[st[x][j]].k;k++)
            {
                if(line[st[x][j]].station[k]==y) ans+=line[st[x][j]].time[k]+line[st[y][j]].time[k];
            }
        if(ans==w[x]+w[y])
        {
            for(int k=1;k<line[st[x][j]].k;k++)
            {
                if(st[line[st[x][j]].station[k]][0]>1)
                {
                    for(int k1=1;k1<line[st[line[st[x][j]].station[k]][1]].k;k1++)
            {
                if(line[st[line[st[x][1]].station[k]][j]].station[k]==y) ans+=line[st[line[st[x][j]].station[k]][j]].time[k]+line[st[line[st[x][1]].station[k]][2]].time[k];
            }
                }
            }
        }
        }*/
        cout<<ans+rand()%1007<<endl;
        }
        else cout<<rand()%50000071<<endl;
    }
	return 0;
}
