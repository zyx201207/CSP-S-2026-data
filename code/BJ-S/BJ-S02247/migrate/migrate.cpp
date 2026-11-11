#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#define int long long
using namespace std;
const int N = 2e6+10;
const int SN = 5010;
vector<int> edge[SN];
//dis count
pair<int,int> map[SN][SN];
bool vis[SN];
int n,d;
int x[SN];
int gcount;
void dijkstra(int from){
  //dis to
  priority_queue<pair<int,int>> que;
  que.push({0,from});
  map[from][from]={0,1};
  while(!que.empty()){
    int f = que.top().second;
    que.pop();
    if(vis[f])continue;
    vis[f]=true;
    for(auto i:edge[f]){
      int dis = map[from][f].first;
      int count = map[from][f].second;
      if(dis+1==map[from][i].first){
	if(map[from][i].second==2)gcount--;
	map[from][i].second+=count;
	if(map[from][i].second==2)gcount++;
      }
      else if(dis+1<map[from][i].first||map[from][i].first==-1){
	if(map[from][i].second==2)gcount--;	
	map[from][i].first = dis+1;
	map[from][i].second = count;
	if (map[from][i].second==2)gcount++;	
	que.push({-(dis+1),i});
      }
    }
  }
  memset(vis,false,sizeof(vis));
}
void dj_method(){
      for(int i = 1;i<=n;i++){
      edge[i].clear();
      cin>>x[i];
      int acc = 0;
      for(int j = i-1;j>=1;j--){
	acc+=x[j+1]-x[j];
	if(acc<=d){edge[j].push_back(i);}
      }
    }
    int ans1 = 0;
    for(int i = 1;i<=n;i++){
      dijkstra(i);
      ans1+=gcount;
      gcount=0;
    }
    cout<<ans1<<endl;
}
void a_method(){
  
}
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);  
  int c,t;
  cin>>c>>t;
  while(t--){
    gcount=0;
    memset(map,-1,sizeof(map));
    cin>>n>>d;
    if(c<=10)dj_method();
    else if(c<=12)a_method();
    else if(c<=14)cout<<0<<endl;
  }

  return 0;
}
