#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int c;//number
int n;//road;
int m;//station
int d,q;
int w[500005];
struct node
{
    int st;
    long long cost;
    int road;
};
struct pgr
{
    int st;
    int en;
};
struct que
{
    int point;
    long long cost;
    int road;
};
pgr r[200005];
vector <node> mp[500005];
int t[505][300005];
bool f1[500005];
bool f2[500005];
long long ans;
int cou1[505][300005];
int cou2[505][300005];
void bfs(int num)
{
    queue <que> q1;//zheng;
    queue <que> q2;//fan
    long long t1;
    long long t2;
    q1.push({r[num].st,w[r[num].st],-1});
    q2.push({r[num].en,w[r[num].en],-1});
    f1[r[num].st]=1;
    f2[r[num].en]=1;
    for(int i=0;i<=mp[r[num].st].size();i++)
    {
        cou1[mp[r[num].st][i].road][r[num].st]=w[r[num].st];
    }
    for(int i=0;i<=mp[r[num].en].size();i++)
    {
        cou2[mp[r[num].en][i].road][r[num].en]=w[r[num].en];
    }
    while(!q1.empty()&&!q2.empty())
    {
        que p1=q1.front();
        que p2=q2.front();
        q1.pop();
        q2.pop();
        //cout<<"true:"<<p1.point<<' '<<p1.cost<<' '<<p1.road<<endl;
        //cout<<"false:"<<p2.point<<' '<<p2.cost<<' '<<p2.road<<endl;
        if(f2[p1.point])
        {
            for(int j=1;j<=n;j++)
            {
                if(cou2[j][p1.point]!=0)
                {

                    if(j!=p1.road)
                        ans=min(ans,cou2[j][p1.point]+t[j][p1.point]+t[p1.road][p1.point]+p1.cost);
                    else
                        ans=min(ans,cou2[j][p1.point]+t[j][p1.point]+p1.cost);
                    //cout<<"cou2:"<<j<<' '<<cou2[j][p1.point]<<' '<<ans<<endl;
                }
            }

        }
        if(f1[p2.point])
        {
            for(int j=1;j<=n;j++)
            {
                if(cou1[j][p2.point]!=0)
                {
                    if(j!=p2.road)
                        ans=min(ans,cou1[j][p2.point]+t[j][p2.point]+t[p2.road][p2.point]+p2.cost);
                    else
                        ans=min(ans,cou1[j][p2.point]+t[p2.road][p2.point]+p2.cost);
                    //cout<<"cou1:"<<j<<' '<<cou1[j][p2.point]<<' '<<ans<<endl;
                }
            }
        }

        for(int i=0;i<mp[p1.point].size();++i)
        {

            if(f1[mp[p1.point][i].st]==0)
            {
                //cout<<mp[p1.point][i].st<<' '<<mp[p1.point][i].road<<endl;
                que op;
                op.cost=p1.cost;
                if(p1.road==-1)
                {
                    op.cost+=t[mp[p1.point][i].road][p1.point];
                    op.road=mp[p1.point][i].road;
                }
                else if(p1.road!=mp[p1.point][i].road)
                {
                    op.cost+=t[p1.road][p1.point]+t[mp[p1.point][i].road][p1.point];
                }
                op.point=mp[p1.point][i].st;


                if(cou1[mp[p1.point][i].road][mp[p1.point][i].st]!=0&&cou1[mp[p1.point][i].road][mp[p1.point][i].st]<op.cost)
                    continue;
                //cout<<"satifantion";
                q1.push(op);
                cou1[mp[p1.point][i].road][mp[p1.point][i].st]=op.cost;
                f1[mp[p1.point][i].st]=1;
            }

        }
        for(int i=0;i<mp[p2.point].size();++i)
        {
            if(f2[mp[p2.point][i].st]==0)
            {
                //cout<<mp[p2.point][i].st<<' '<<mp[p2.point][i].road<<endl;
                que op;
                op.cost=p2.cost;
                if(p2.road==-1)
                {
                    op.cost+=t[mp[p2.point][i].road][p2.point];
                    op.road=mp[p2.point][i].road;
                }
                else if(p2.road!=mp[p2.point][i].road)
                {
                    op.cost+=t[p2.road][p2.point]+t[mp[p2.point][i].road][p2.point];
                }
                op.point=mp[p2.point][i].st;

                if(cou2[mp[p2.point][i].road][mp[p2.point][i].st]!=0&&cou2[mp[p2.point][i].road][mp[p2.point][i].st]<op.cost)
                    continue;
                q2.push(op);
                cou2[mp[p2.point][i].road][mp[p2.point][i].st]=op.cost;
                f2[mp[p2.point][i].st]=1;
            }

        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;++i)
    {
        int k;
        cin>>k;
        node last;
        for(int j=1;j<=k;++j)
        {
            node a;
            cin>>a.st>>a.cost;
            t[i][a.st]=a.cost;
            a.road=i;
            if(j==1)
            {
                last=a;
                continue;
            }
            mp[a.st].push_back(last);
            mp[last.st].push_back(a);
            last=a;
        }
    }

    for(int i=1;i<=q;i++)
    {
        cin>>r[i].st>>r[i].en;
        ans=99999999999;
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        memset(cou1,0,sizeof(cou1));
        memset(cou2,0,sizeof(cou2));
        bfs(i);
        cout<<ans<<endl;
    }
    return 0;
}
