#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[200006],dis[200006],book[200006],d,c,n,t;
queue<int>q;//int fa[22][2000006];
int ans;
int col[200006];bool inq[200006];
void bfs2(int i)
{
    q.push(i);
    col[i]=1;
    dis[1]=1;
    inq[i]=1;
    while(!q.empty())
    {
        int pos=q.front();
        q.pop();
        inq[pos]=0;
        if(col[pos]==2)
        {
			ans++;
		}
        else if(col[pos]>2)continue;
        for(int j=pos+1;x[j]-x[pos]<=d&&j<=n;j++)
        {
			if(dis[j]==0||dis[j]==dis[pos]+1)
			{	
				col[j]+=col[pos];
				dis[j]=1+dis[pos];
				if(inq[j]==0)
				{
					q.push(j);
					inq[j]=1;
				}
			}
			
        }
    }
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    //memset(book,0,sizeof(book));
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        
       
        ans=0;
        for(int i=1;i<=n;i++)
        {
			for(int j=1;j<=n;j++)
			{
				col[j]=0;
				dis[j]=0;
			}
            bfs2(i);
           
        }
   
        cout<<ans<<'\n';
    }
    return 0;
}
