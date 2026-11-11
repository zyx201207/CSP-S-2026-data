#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[500005],a[505][15005],t[505][15005],maxn=2147483647,x,y;
vector<int> de[505];
int check(int xx,int dd)
{
    if(xx==0||dd==0)
        return 0;
    int cur=1;
    while(a[dd][cur]!=xx)
        cur++;
    return cur;
}
void dfs(int xx,int yy,int sum,int dep)
{
    if(xx==yy)
    {
        sum += t[dep][check(yy,dep)] + w[x] + w[y];
        maxn=min(maxn,sum);
        return;
    }
    for(int e:de[xx])
    {
        if(e!=dep)
            dfs(a[e][check(xx,e)+1],yy,sum+t[e][check(xx,e)]+t[dep][check(xx,dep)],e);
        else
            dfs(a[dep][check(xx,dep)+1],yy,sum,dep);
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
        cin >> w[i];
    for(int i=1;i<=n;i++)
    {
        cin >> k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin >> a[i][j] >> t[i][j];
            de[a[i][j]].push_back(i);
        }
    }
    for(int i=1;i<=q;i++)
    {
        maxn=2147483647;
        cin >> x >> y;
        if(x>y)
            swap(x,y);
        dfs(x,y,0,0);
        cout << maxn << endl;
    }
    return 0;
}
