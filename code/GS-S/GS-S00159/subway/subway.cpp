#include <bits/stdc++.h>
using namespace std ;
int c , n , m , d , qq ;
int w[100005] ;
long long dis[200000] ;
bool vis[200000];
struct Edge 
{
	int v ;
	int w ;
};
vector<Edge>e[10000000] ;
struct Point
{
	int p ;
	int w ;
}q[100005];
bool cmp(Point a , Point b)
{
	return a.w > b.w ;
}
void addEdge(int u , int v , int w)
{
	e[u].push_back({v , w});
	e[v].push_back({u , w}); 
}
void dijkstra(int s)
{
	//cout << "inner first" << endl ;
	memset(vis , sizeof(vis) , 0);
	memset(dis , sizeof(dis) , 0x3f3f3f);
	vis[s] = true ; 
	dis[s] = 0 ;
	int num = 0 ;
	int u ;
	//cout << "inner begin" <<" " <<s << " " << e[s].size()<< endl ;
	for(int i = 0 ; i < e[s].size() ; i++)
	{
		num++;
		q[num] = {e[s][i].v , e[s][i].w};
		dis[q[num].p] = q[num].w ;
	}
	//cout <<"kkk"<<endl ;
	sort(q + 1 , q + num + 1 , cmp) ;
	//cout <<"www"<< " " << num <<endl;
	while(num != 0)
	{
		u = q[num].p ;
		num-- ;
		//cout << "inner number" << endl ;
		if(vis[u] != true){
			vis[u] = true ;
			for(int i = 0 ; i < e[u].size() ; i++)
			{
				if(vis[e[u][i].v] != true)
				{
					dis[e[u][i].v] = min(dis[e[u][i].v] , dis[u] + e[u][i].w);
					num++ ;
					q[num] = {e[u][i].v , dis[e[u][i].v]};
				}
			}
			sort(q + 1 , q + num + 1 , cmp) ;
		}
	}
	return ;	 
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> qq ;
	for(int i = 1 ; i <= m ; i++)
	{
		cin >> w[i] ;
	}
	int k , u , t ; 
	//cout << "---1---"<<endl;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> k ;
		for(int j = 1 ; j <= k ; j++)
		{
			cin >> u >> t ;
			addEdge(u , m + i , t) ;
			//cout << u << " " << e[u].size()<<endl ;
		}
	}
	//cout << "---2---" << endl ;
	int x , y ;
	while(qq--)
	{
		//cout << "dijbegin" << endl ;
		cin >> x >> y ;
		//cout <<x << " " << e[x].size()<<endl;
		//cout << "x y ready" << endl ;
		dijkstra(x);
		//cout <<"dij"<<qq+1 <<endl ;
		cout << dis[y] + w[x] + w[y]<<endl;
	}
	return 0 ;
}
