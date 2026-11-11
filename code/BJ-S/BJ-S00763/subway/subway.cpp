#include<bits/stdc++.h>
#define pow power
#define ll long long
#define ull unsigned long long
using namespace std;
template<typename T>void read(T &x)
{
    x=0;int f=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
    for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
    x*=f;
}
template<typename T>void write(T x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
template<typename T>void writeln(T x){write(x);putchar('\n');}
template<typename T>void writesp(T x){write(x);putchar(' ');}
const int N=505,M=5e5+5;
const ll INF=1e18;
int cid,n,m,d,q;
int w[M];
vector<pair<int,ll>> vec[M];
ll dst[N][N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(cid);read(n);read(m);read(d);read(q);
    for(int i=1;i<=m;i++) read(w[i]);
    for(int i=1;i<=n;i++)
    {
        int len;read(len);
        for(int j=1;j<=len;j++)
        {
            int x;ll v;
            read(x);read(v);
            vec[x].push_back(make_pair(i,v));
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                dst[i][j]=INF;
    for(int u=1;u<=m;u++)
        for(int i=0;i<vec[u].size();i++)
            for(int j=i+1;j<vec[u].size();j++)
                dst[vec[u][i].first][vec[u][j].first]=min(dst[vec[u][i].first][vec[u][j].first],vec[u][i].second+vec[u][j].second);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dst[i][j]=dst[j][i]=min(dst[i][j],dst[j][i]);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dst[i][j]=min(dst[i][j],dst[i][k]+dst[k][j]);
    while(q--)
    {
        int x,y;
        read(x);read(y);
        ll ans=INF;
        for(int i=0;i<vec[x].size();i++)
            for(int j=0;j<vec[y].size();j++)
                ans=min(ans,vec[x][i].second+dst[vec[x][i].first][vec[y][j].first]+vec[y][j].second);
        ans+=w[x]+w[y];
        writeln(ans);
    }
    return 0;
}
//g++ tmp.cpp -o tmp -std=c++14 -O2 -Wall -Wextra -static