#include<bits/stdc++.h>
using namespace std;
int w[500010];
vector<pair<int,int>> g[500010];
int st[500010];
int d[500010];
int a[510][500010];
int t[510][500010];
int kk[510];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,dd,q;
    cin>>c>>n>>m>>dd>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>kk[i];
        for(int j=1;j<=kk[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    if(n==1)
    {
		while(q--)
		{
			int S,E;
			cin>>S>>E;
			cout<<w[S]+w[E]+t[1][S]+t[1][E]<<"\n";
		}
	}
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=kk[i];j++)
        {
            for(int sdfh=j+1;sdfh<=kk[i];sdfh++)
            {
                g[a[i][j]].push_back({a[i][sdfh],t[i][j]+t[i][sdfh]});
                g[a[i][sdfh]].push_back({a[i][j],t[i][j]+t[i][sdfh]});
            }
        }
    }
    while(q--)
    {
        int S,E;
        cin>>S>>E;
        queue<int> q;
        q.push(S);
        memset(d,0x3f,sizeof(d));
        memset(st,0,sizeof(st));
        st[S]=1;
        d[S]=0;
        while(q.size())
        {
            int t=q.front();
            q.pop();
            st[t]=false;
            for(auto it:g[t])
            {
                int v=it.first;
                int w=it.second;
                if(d[v]>d[t]+w)
                {
                    d[v]=d[t]+w;
                    if(!st[v])
                    {
                        q.push(v);
                        st[v]=true;
                    }
                }
            }
        }
        cout<<d[E]+w[S]+w[E]<<"\n";
    }
}
/*
 Why that I find the wrong about T2 at 15:30 p.m.,but the answer is at 17:30 p.m.?
 Why?
 bao wo shang da fen , rp ++ , na dao lan gou.
 luogu uid:1160828
 J:100+100+20+50=270?
 S:60+50+eps?
*/
