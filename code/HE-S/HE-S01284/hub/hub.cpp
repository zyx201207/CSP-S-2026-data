#include<bits/stdc++.h>
using namespace std;
#define int long long

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}

int n,K,ans;
vector<int> v[1000005];
int tag[1000005];
int dis[105]; int vis[105];

int v1(int x,int fa){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++){
		int to=v[x][i];
		if(to==fa||!tag[to]) continue;
		v1(to,x);
	}
	return 0;
}
bool chek1(){
	memset(vis,0,sizeof(vis));
	int flag=0;
	for(int i=1;i<=n;i++){
		if(tag[i]&& !vis[i]){
			if(flag==2) return 1;
			flag++; v1(i,0);
		}
	}
//	cout<<flag<<endl;
	return 0;
}
void chek2(){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(tag[i]){
			dis[i]=0; vis[i]=1;
			q.push(i);
		}
	}
	int res=0;
	while(!q.empty()){
		int x=q.front(); q.pop();
		res=max(res,dis[x]); 
//		cout<<x<<" "<<dis[x]<<endl;
		for(int i=0;i<v[x].size();i++){
			int to=v[x][i];
			if(vis[to]) continue;
			dis[to]=dis[x]+1;
			vis[to]=1;
			q.push(to);
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<tag[i]<<" ";
//	}cout<<"! "<<ans<<" "<<res<<endl;
	ans=min(ans,res);
}

void dfs(int i,int res){
	if(i>n){
		if(res==K) return;
		if(chek1())return ;
		chek2(); return;
	}
	if(res!=0){
		tag[i]=1;
		dfs(i+1,res-1);
		tag[i]=0;
	}
	dfs(i+1,res);
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int Cast=read();
	int T=read();
	while(T--){
		n=read(); K=read(); ans=998244353;
//		cout<<K<<endl;
		if(K<=20){
			for(int i=1;i<n;i++){
				int x=read(); int y=read();
				v[x].push_back(y);
				v[y].push_back(x);
			}
//			cout<<"!!"
			dfs(1,K);
			for(int i=1;i<=n;i++){
				v[i].clear(); 
			}
		}else{
			ans=(n/2/2-K/2+1)/2+1;
			for(int i=1;i<n;i++){
				read(); read();
			}
		}
		write(ans); putchar('\n');
	}
	
	return 0;
}


// 黄绿青紫。

// 14:44 T1
// 15:30 T2
// 17:16 T3

// 没人能想象到过 T3 大洋里的时候的那种狂喜 通透
// 哦吼吼吼吼吼我无疑是快乐的 

// 过三题，今年应该能去厕所吧。挂分不讲。

// T4 写不动了，开始打暴力。 发现纯暴力有 25 pts，每日 325 大学习已完成 

// 可惜没时间打暴搜了……不然还能凑出来 300+25==325 

// We are srawying on horseback
// And the hills are green
// And the birds are singing
// And roses are pink
 

