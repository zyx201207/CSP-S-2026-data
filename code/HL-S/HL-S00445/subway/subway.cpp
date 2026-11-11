#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int c,m,n,d,q;
int w[N],k[1000];
vector<int> a[700],t[700],s[N],u[700];
//vector<pair<int,int> >p[500];
int v[700][700];
bool tujing(int line,int station)
{
    for(int i:a[line])
    {
        if(i==station)
        {
            //cout<<"    "<<i<<endl;;
            return true;
        }
    }
    //cout<<"false";
    return false;
}
void real_main()
{
    int x,y;
    cin>>x>>y;
    priority_queue<pair<int,int> > q;
    for(int ii=0; ii<s[x].size(); ii++)
    {
        //cout<<ii;
        int th;
        for(int jj=0; jj<k[s[x][ii]]; jj++)
        {
            //cout<<jj;
            if(a[s[x][ii]][jj]==x)
            {
                th=jj;
                break;
            }
        }
        q.push({t[ii][th],s[x][ii]});
    }
    //cout<<"ok1"<<endl;
    while(!q.empty())
    {
        int cnt=q.top().second;
        //cout<<q.top().first<<' '<<q.top().second<<' '<<u[cnt].size()<<endl;

        if(tujing(cnt,y));
        {
            //cout<<"true";
            int th;
            for(int jj=0; jj<k[cnt]; jj++)
            {
                if(a[cnt][jj]==cnt)
                {
                    th=jj;
                    break;
                }
            }
            cout<<q.top().first+w[x]+w[y]+t[cnt][th]<<endl;
            return;
        }
        for(int z=0; z<u[cnt].size(); z++)
        {
            //cout<<"  next:"<<u[cnt][z]<<endl;
            q.push({v[cnt][u[cnt][z]]+q.top().first,u[cnt][z]});
        }
        q.pop();
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1; i<=m; i++)
    {
        cin>>w[i];
    }
    for(int i=1; i<=n; i++) //i为线路编号
    {
        //cout<<endl<<i;
        cin>>k[i];
        for(int j=1; j<=k[i]; j++)
        {
            //cout<<' '<<j;
            int t1,t2;
            cin>>t1>>t2; //t1站点 t2是站台时间
            a[i].push_back(t1);
            t[i].push_back(t2);  //t[i][j]表示线路i上,a[i][j]站台花费的时间
            s[t1].push_back(i);  //t1站台有i途径
            for(int ii=0; ii<s[t1].size()-1; ii++) //s[ii]表示经过该站点的地铁编号
            {
                //cout<<"联通"<<i<<"与"<<s[t1][ii]<<endl;
                u[s[t1][ii]].push_back(i);   //ii与i联通
                u[i].push_back(s[t1][ii]);   //i与ii联通
                int th;
                for(int jj=0; jj<k[s[t1][ii]]; jj++)
                {
                    if(a[s[t1][ii]][jj]==t1)
                    {
                        th=jj;
                        break;
                    }
                }
                if(v[i][ii]!=0)
                    v[i][ii]=min(v[i][ii],t2+t[s[t1][ii]][th]);
                else
                    v[i][ii]=t2+t[s[t1][ii]][th];

            }
        }
    }
    for(int i=1; i<=q; i++)
    {
        real_main();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/**
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

**/
