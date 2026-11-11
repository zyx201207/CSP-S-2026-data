#include<bits/stdc++.h>
typedef long long ll ;
using namespace std ;
const int MAXN = 5e6 + 10 ; 

int c , n , m , d , q ,head[MAXN] , cnt ;
ll dis[MAXN];
bool vis[MAXN] ;

struct Edge{
	int to , nxt , w ;
}edge[MAXN << 1];

void add(int u , int v , int w){
	edge[cnt].to = v ;
	edge[cnt].w = w ;
	edge[cnt].nxt = head[u] ;
	head[u] = cnt ++ ;
}

struct node{
	int id , dis ;
	bool operator <(const node &a)const{
		return a.dis < dis ;
	}
};

priority_queue <node> dl ;

void dijkstra(int s){
	memset(vis , false , sizeof(vis)) ;
	while(!dl.empty()){
		dl.pop() ;
	}
	fill(dis , dis + m , 0x3f3f3f3f) ;
	dis[s] = 0 ;
	dl.push({s , 0}) ;
	
	while(!dl.empty()){
		node temp = dl.top() ;
		int u = temp.id ;
		dl.pop() ;
		
		if (!vis[u]){
			vis[u] = true ;
			
			for (int i = head[u] ; ~i ; i = edge[i].nxt){
				int v = edge[i].to ;
				
				if (dis[v] > dis[u] + edge[i].w){
					dis[v] = dis[u] + edge[i].w ;
					
					dl.push({v , dis[v]}) ;
				}
			}
		}
	}
}

int main(){
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
	cin>>c>>n>>m>>d>>q ;
	
	memset(head , -1 , sizeof(head)) ;
	
	for (int i = 1 ; i <= m ; ++i){
		ll w ;
		cin>>w;
		add(i , i + m , w) ;//i + m µØÌú¿Ú£¬iÕ¾Ìü£¬i+2mÕ¾Ì¨ 
		add(i + m , i , w) ;
	} 
	
	for (int i = 1 ; i <= m ; ++i){
		for (int j = 1 ; j <= m ; ++j){
			add(i + 2 * m , j + 2 * m , 0) ;
		}
	}
	
	for (int i = 1 ; i <= n ; ++i){
		int k ;
		cin>>k ;
		for (int j = 1 ; j <= k ; ++j){
			int a , t ;
			cin>>a>>t ;
			add(a , a + 2 * m , t) ;
			add(a + 2 * m , a , t) ;
		}
	}
	
	for (int i = 1 ; i <= q ; ++i){
		int x , y ;
		cin>>x>>y ;
		dijkstra(x + m) ;
		
		cout<<dis[y + m]<<"\n";
	}

	return 0 ;
}
