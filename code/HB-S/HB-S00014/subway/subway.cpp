#include <bits/stdc++.h>
using namespace std;
struct node{
    int xl[25],k,dj[25],sj[25];
}zt[505];
struct node2{
    int ti,x,xl,dj;
};
int c,n,m,d,q;
int w[500005],k[505],a[505][500005],t[505][500005];
bool book[505];
int bfs(int x,int y)
{
    queue<node2> q;
    q.push({w[x],x,0,0});
    while(!q.empty())
    {
		//cout<<q.front().ti<<" "<<q.front().x<<endl;
		if(q.front().x==y)
		{
			return q.front().ti;
		}
		for(int j=-1;j<=1;j+=2)
		{
			for(int i=1;i<=zt[q.front().x].k;i++)
			{
				if(book[a[q.front().x][zt[q.front().x].dj[zt[q.front().x].xl[i]]+j]]==0)
				{
					book[a[q.front().x][zt[q.front().x].dj[zt[q.front().x].xl[i]]+j]]=1;
					if(q.front().xl==0||zt[q.front().x].xl[i]==q.front().xl)
						q.push({
						   q.front().ti+zt[q.front().x].sj[i]
						   ,
						   a[q.front().x][zt[q.front().x].dj[zt[q.front().x].xl[i]]+j]
					       ,
					       zt[q.front().x].xl[i]
					       ,
					       zt[q.front().x].dj[zt[q.front().x].xl[i]]+j
					       });
					else
						q.push({
						   q.front().ti+zt[q.front().x].sj[i]+t[q.front().xl][q.front().dj]+zt[q.front().x].sj[i]
						   ,
						   a[q.front().x][zt[q.front().x].dj[zt[q.front().x].xl[i]]+j]
					       ,
					       zt[q.front().x].xl[i]
					       ,
					       zt[q.front().x].dj[zt[q.front().x].xl[i]]+j
					       });
				}
			}
		}
		q.pop();
    }
    return 0;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            zt[a[i][j]].xl[++zt[a[i][j]].k]=i;
            zt[a[i][j]].dj[zt[a[i][j]].k]=j;
            zt[a[i][j]].sj[zt[a[i][j]].k]=t[i][j];
        }
    }
    int x,y;
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        cout<<bfs(x,y)+10<<endl;
    }
    return 0;
}
