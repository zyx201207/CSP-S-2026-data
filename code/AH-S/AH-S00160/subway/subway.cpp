#include<bits/stdc++.h>
using namespace std ;

const int N  = 510 , M = 2*N;

int c, n, m, d, q ;

int wp[N] ;

int h[N] , np[M] , ne[M] , w[M] , idx = 0  ;

void add(int a , int b , int t){
np[idx] = b , ne[idx] = h[a] , w[idx] = t , h[a] = idx++ ;
}

int bfs(int x , int y){

priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> >>que ;
long long dist[N];
bool st[N] ;

memset(dist , 0x3f , sizeof dist) ;
memset(st , 0 , sizeof st) ;

que.push({0 , x}) ;

while(que.size()){

   pair<int,int> t = que.top();

    int dst = t.first , point = t.second;

    if(st[point])continue ;
    st[point] = true ;

    for(int i = point ; ~i ; i = ne[i]){
        int j = np[i] ;

        if(dist[j] > dst + w[i]){
            dist[j] = dst + w[i] ;
            que.push({dist[j] , j}) ;
        }
    }

    return dist[y] ;
}

}

int main(){
  freopen("subway.in" , "r" , stdin) ;
  freopen("subway.out" , "w" , stdout) ;

  memset(h , -1 ,sizeof h) ;


  cin>>c>>n>>m>>d>>q ;

  for(int i = 1 ; i <= m ; i ++)cin>>wp[i] ;

  for(int i = 1 ; i <= n ; i ++){

    int a , t ;
    int k ;

    scanf("%d" , &k) ;

    for(int j = 1 ;j <= k ; j ++){
        scanf("%d%d" , &a , &t) ;

        add(a , m + i , t + wp[a]) ;
        add(m + i , a , t + wp[a]) ;
    }
  }
while(q --){
    int x , y ;

    cout<<bfs(x , y)<<endl ;
}

  return 0 ;
}
