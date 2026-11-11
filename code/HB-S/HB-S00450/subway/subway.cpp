#include <bits/stdc++.h>

using namespace std;
const int NUM=5*1e3+5;
int w[NUM];
int line[30][NUM];
int haha[NUM];
int cao[NUM];
vector <vector<int>> t;
int dis[NUM][NUM];

int find1(int x,int y)
{
    //cout<<x<<" "<<y<<" ";
    if(x>y)
        swap(x,y);

    if(x==y)
        return 0;
    if(dis[x][y])
    {
        //cout<<dis[x][y]<<endl;
        return dis[x][y];

    }
    int i,ans=0x3f3f3f3f;
    //i=t[x].begin();
    for(i=t[x].begin();i<=t[x].end();i++)
    {
        ans=min(ans,dis[x][i]+find1(i,y));
    }
    t[x].push_back(y);
    cao[x]++;
    dis[x][y]=ans;
    //cout<<dis[x][y]<<endl;
    return ans;
}

int main()
{

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,da,q;
    cin>>c>>n>>m>>da>>q;
    //cout<<c<<" "<<n<<" "<<m<<" "<<da<<" "<<q<<" ";
    int i,j;
    for(i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    int k;
    for(i=1;i<=n;i++)
    {
        cin>>k;
        for(j=1;j<=k;j++)
        {
            int num,v;
            cin>>num>>v;
            haha[j]=num;
            line[n][num]=v;
        }
        for(j=1;j<k;j++)
        {
            int xa=haha[j];
            int ya=haha[j+1];
            if(xa>ya)
                swap(xa,ya);
            t[xa].push_back(ya);
            //cout<<'T'<<" "<<xa<<" "<<ya<<" "<<endl;
            //t[y].push_back(x);
            dis[xa][ya]=line[n][xa]+line[n][ya];
            cao[xa]++;
            //dis[y][x]=line[d][x]+line[d][y];
        }
        int xa=haha[1],ya=haha[k];
        t[xa].push_back(ya);
       // cout<<'t'<<" "<<xa<<" "<<ya<<" "<<endl;
        //t[y].push_back(x);
        dis[xa][ya]=line[n][xa]+line[n][ya];
        cao[xa]++;
        //dis[y][x]=line[d][x]+line[d][y];
    }
    int a,b;
    for(i=1;i<=q;i++)
    {
        cin>>a>>b;
        int ans=w[a]+w[b];
        if(a>b)
            swap(a,b);
        ans+=find1(a,b);
        cout<<ans<<endl;
    }
    return 0;
}
