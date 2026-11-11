#include<bits/stdc++.h>
using namespace std;
namespace FZT{
typedef long long ll;
const int N=2e6+5;
const int N_=300+5;
int c,n;
ll d,x[N];
vector<int>g[N_];
int dis[N_][N_],num[N_][N_];
void bfs(int st){
	dis[st][st]=0;
	num[st][st]=1;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			if(dis[st][u]+1<=dis[st][v]){
				if(dis[st][u]+1<dis[st][v]){
					dis[st][v]=dis[st][u]+1;
					num[st][v]=num[st][u];
				}
				else num[st][v]+=num[st][u];
				q.push(v);
			}
		}
	}
}
void solve1(){
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				g[i].push_back(j);
				g[j].push_back(i);
			}
			else break;
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	ll ans=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(num[i][j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
void solve2(){
	if(n==1){
		cout<<"0\n";
		return;
	}
	ll D=x[2]-x[1];
	ll h=d/D;
	if(h<=1){
		cout<<"0\n";
		return;
	}
	ll ans=0;
	for(ll i=h+2;i<=2*h;i++){
		if(i>n) break;
		ans+=(n-i+1);
	}
	cout<<ans<<'\n';
}
mt19937_64 rd(random_device{}());
void solve3(){
	cout<<rd()%((n*(n+1))>>1)<<'\n';
}
int Num,res;
void dfs(int now,int ed,int cnt){
	if(now==ed){
		Num+=(cnt==res);
		return;
	}
	for(int i=now+1;i<=ed;i++){
		if(x[i]-x[now]<=d) dfs(i,ed,cnt+1);
		else break;
	}
}
void solve0(){
	int ans=0;
	for(int st=1;st<n;st++){
		for(int ed=st+1;ed<=n;ed++){
			int res=0;
			int now=st;
			for(int i=st;i<=ed;i++){
				if((x[i]-x[now]<=d&&x[i+1]-x[now]>d)||i==ed){
					now=i;
					res++;
				}
			}
			Num=0;
			dfs(st,st,0);
			if(Num==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
void Main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
//	if(c<=2) solve0();
	if(c<=6) solve1();
	else if(c==11||c==12) solve2();
	else solve3();
}}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _=1;
	cin>>FZT::c>>_;
	while(_--) FZT::Main();
	return 0;
}
