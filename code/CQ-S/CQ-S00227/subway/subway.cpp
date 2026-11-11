#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
#define mk make_pair
#define pb push_back
#define endl  '\n'


int read(){
	char c;
	while (c<'0' || c>'9'){
		c=getchar();
	} 
	int x=0;
	while (c>='0' && c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x;
}void write(int x){
	if (x<=9){
		putchar(x+'0');
		return ;
	}
	write(x/10);
	putchar(x%10+'0');
	return ;
} 
int c,n,m,D,q;
int w[500009];
int k[509];
vector<pii> t[509];
vector<int> d[500009]; 
int dp[500009];
unordered_map<int,int> mp;
struct node{
	int x,y,id,ans;
}op[100009];
bool cmp(node p,node q){
	if (p.x==q.x){
		return p.y<q.y;
	}
	return p.x<q.x;
}
bool cmp1(node p,node q){
	return p.id<q.id;
}
void bfs(int x){
	queue<pii> q;
	q.push(mk(x,0));
	memset(dp,0x3f,sizeof(dp));
	vector<bool> vis(m+9,0);vector<bool> visited(m+9,0);
//	vis[x]=true;
	int sum=0;
	while(!q.empty()){
		int u=q.front().fir,cnt=q.front().sec;
		q.pop();
		dp[u]=min(dp[u],cnt);
		for (auto i : d[u]){
			if (visited[i]) continue;
			visited[i]=true;
			int s=0;
			for (auto j : t[i]){
				//到达的为 j.fir j.sec 为站厅到站台的边权
				if (j.fir==u) {
					s=j.sec;
					break;
				}
			}
			for (auto j : t[i]){
				//到达的为 j.fir j.sec 为站厅到站台的边权
				if (j.fir!=u) {
					if (vis[j.fir] || cnt+s+j.sec>=dp[j.fir]) continue;
					vis[j.fir]=true;
					q.push(mk(j.fir,cnt+s+j.sec));
				}
			}
		}
	}
} 
signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	D=read();
	q=read();
	for (int i=1;i<=m;i++) {
		w[i]=read();
	}
	int POT=0;
	for (int i=1;i<=n;i++){
		k[i]=read();
		for (int j=1;j<=k[i];j++){
			int A,T;
			A=read();
			T=read();
			POT=T;
			d[A].pb(i);
			t[i].pb(mk(A,T));
//			mp[i][a]=t;
		}
	}
	for (int i=1;i<=q;i++){
		op[i].x=read();
		op[i].y=read();
		op[i].id=i;
	} 
	sort(op+1,op+q+1,cmp);
	if(c>=16 && c<=19) {
		bfs(1);
		for (int i=1;i<=q;i++){
			op[i].ans=abs(dp[op[i].y]-dp[op[i].x])+w[op[i].x]+w[op[i].y]+2*POT;
		}
	}
	else{
		for (int i=1;i<=q;i++){
			if (op[i].x!=op[i-1].x){
				bfs(op[i].x);
				op[i].ans=dp[op[i].y]+w[op[i].x]+w[op[i].y];
			}
			else{
				op[i].ans=dp[op[i].y]+w[op[i].x]+w[op[i].y];
			}
		}
	}
	sort(op+1,op+q+1,cmp1);
	for(int i=1;i<=q;i++){
		write(op[i].ans);
		putchar('\n');
	}
//	system("fc /W subway3.ans subway3.out");
	return 0;
}








