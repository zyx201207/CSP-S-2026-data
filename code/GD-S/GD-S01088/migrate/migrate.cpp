#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
using std::cin;using std::cout;
using std::string;using std::vector;
typedef long long ll;
const int N=2e6+10;
namespace zyh{
	vector<int> to[N];
	std::queue<int> q;
	void add(int u,int v){to[u].push_back(v);}	
	int n;
	ll d,ans;
	int dis[N],num[N];
	int bfs(int x){
		for(int i=1;i<=n;i++) dis[i]=-1,num[i]=0;
		dis[x]=0,num[x]=1;
		int res=0;
		q.push(x);
		while(!q.empty()){
			int now=q.front();
			q.pop();
			for(auto i:to[now]){
				if(dis[i]==-1){
					dis[i]=dis[now]+1;
					num[i]=num[now];
					q.push(i);
				}else if(dis[i]==dis[now]+1) num[i]+=num[now];
			}
		}
		for(int i=x+1;i<=n;i++){
			if(num[i]==2) res++;
		}
		return res;
	}
	ll pos[N];
	void work(){
		cin>>n>>d;
		for(int i=1;i<=n;i++) to[i].resize(0);
		for(int i=1;i<=n;i++) cin>>pos[i];
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>0;j--){
				if(pos[i]-pos[j]>d) break;
				add(i,j);
			}
			for(int j=i+1;j<=n;j++){
				if(pos[j]-pos[i]>d) break;
				add(i,j);
			} 
		}
		ans=0;
		for(int i=1;i<=n;i++) ans+=bfs(i);
		cout<<ans<<'\n';
	}
	int c,t;
	signed lqr(){
		cin>>c>>t;
		while(t--) work();
		return 0;
	}
}
void IO_set(string str){
	string s1=str+".in",s2=str+".out";
	freopen(s1.c_str(),"r",stdin);
	freopen(s2.c_str(),"w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
}
signed main(){
	IO_set("migrate");
	return zyh::lqr();
}
//40pts 17:00
