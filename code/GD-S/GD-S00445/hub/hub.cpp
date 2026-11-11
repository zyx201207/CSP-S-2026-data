#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
typedef long long ll;
namespace my{
	template<typename now_type>now_type max(now_type x,now_type y){return x>y?x:y;}
	template<typename now_type>now_type min(now_type x,now_type y){return x<y?x:y;}
};
int n,k;
std::vector<std::vector<int>>edge;
std::vector<bool>chosen;
bool check(){
	std::vector<int>father(n+1);
	for(int i=1;i<=n;i++) father[i]=i;
	auto get_father=[&](int now)->int{
		std::stack<int>stk;
		while(father[now]!=now){
			stk.push(now);
			now=father[now];
		}
		while(!stk.empty()){
			father[stk.top()]=now;
			stk.pop();
		}
		return now;
	};
	for(int u=1;u<=n;u++){
		if(!chosen[u]) continue;
		for(int v:edge[u]){
			if(chosen[v]){
				int fau=get_father(u);
				int fav=get_father(v);
				father[fav]=fau;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!chosen[i]) continue;
		if(get_father(i)==i) cnt++;
	}
	return cnt<=2;
}
int ans;
int work(){
	int res=0;
	std::vector<int>dis(n+1,1e9);
	std::queue<int>q;
	std::vector<char>vis(n+1,0);
	for(int i=1;i<=n;i++) 
		if(chosen[i])
			dis[i]=0,q.push(i),vis[i]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		res=my::max(res,dis[u]);
		for(int v:edge[u]){
			if(vis[v]) continue;
			dis[v]=dis[u]+1;
			q.push(v);
			vis[v]=1;
		}
	}
	return res;
}
void brute(int now,int choose){
	if(now>n){
		if(choose!=k) return;
		if(!check()) return;
//		for(int i=1;i<=n;i++) printf("%d ",(int)chosen[i]);
//		puts("");
		ans=my::min(ans,work());
	}
	if(choose>k) return;
	if(n-now+1+choose<k) return;
	chosen[now]=1;
	brute(now+1,choose+1);
	chosen[now]=0;
	brute(now+1,choose);
	return;
}
void solve(int c){
	scanf("%d%d",&n,&k);
	edge.assign(n+1,std::vector<int>());
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	if((1<=c&&c<=3)||c==7){
		chosen.assign(n+1,0);
		ans=1e9;
		brute(1,0);
		printf("%d\n",ans);
	}
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c;
	scanf("%d",&c);
	int T=1;
	scanf("%d",&T);
	while(T--) solve(c);
	return 0;
}
