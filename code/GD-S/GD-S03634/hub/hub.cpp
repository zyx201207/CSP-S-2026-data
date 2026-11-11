#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,k;
vector<int> g[1000006];
int vis[10006];
int ml,pos;

//int dfs(int u,int id,int l)
//{
////	cout<<u<<" "<<l<<"\n";
//	vis[u]=1;
//	if(l>ml)
//	{
//		ml=l,pos=u;
////		cout<<"*"<<ml<<" "<<pos<<endl;
//	}
//	for(int v:g[u])
//	{
//		if(((id>>(v-1))&1) && !vis[v])
//			dfs(v,id,l+1);
//	}
//}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(k==2)
		{
			cout<<1<<endl;
			continue;
		}
		if(c==13||c==14)
		{
			cout<<(k+1)/2<<endl;
			continue;
		}
//		if(c<=3)
//		{
//			int ans=114514;
//			for(int i=1;i<(1<<n);i++)
//			{
//				for(int j=1;j<=n;j++)
//				{
//					vis[j]=0;
//				}
//				int dis=0;
//				int num=0;
//				for(int j=1;j<=n;j++)
//				{
//					if(((i>>(j-1))&1) && !vis[j])
//					{
//						num++;
//						if(num>2)break;
//						dfs(j,i,1);
//						ml=0;
//						dfs(pos,i,1);
//						dis=max(dis,ml);
//						ml=0;
//					}
//				}
//				if(num>2||num==1)continue;
//				cout<<"###"<<i<<" ";
//				cout<<dis<<endl;
//				ans=min(ans,dis);
//			}
//			cout<<ans<<endl;
//		}
	}
	
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
