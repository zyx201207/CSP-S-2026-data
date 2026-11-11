/*永远铭记------丁浩文------史诗级大帅哥*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define pii pair<int,int>
#define pll pair<ll,ll>
ll read(){
	char ch=getchar();
	int f=1;
	ll x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
//多测不清空，保龄两行泪
const int N=109,INF=2e9+999;
int c,t;
int n,k;
int dis[N][N];
//io
void input(){
	n=read(),k=read();
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		dis[u][v]=dis[v][u]=1;
	}
}
//floyed
void floyed(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
//集 
struct JI{
	int fa,siz;
}ji[N];
void init(){
	for(int i=1;i<=n;i++)ji[i]={i,1};
} 
int cha(int now){
	if(ji[now].fa==now)return now;
	return ji[now].fa=cha(ji[now].fa);
}
bool bing(int u,int v){
	u=cha(u),v=cha(v);
	if(u==v)return 0;
	if(ji[u].siz<ji[v].siz)swap(u,v);
	ji[v].fa=u;
	ji[u].siz+=ji[v].siz;
	return 1;
} 
//solve
int ans=INF;
bool bo[N];
void check(){
	init();
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dis[i][j]==1&&bo[i]&&bo[j]){
				cnt+=bing(i,j);
			}
		}
	}
	if(cnt>=k-2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			int minn=INF;
			for(int j=1;j<=n;j++){
				if(bo[j]){
					minn=min(minn,dis[i][j]);
				}
			}
			maxx=max(maxx,minn);
		}
		ans=min(ans,maxx);
	}
}
void baoli(int now,int cnt){
	if(cnt==k){
		check();
		return;
	}
	if(now>n)return;
	baoli(now+1,cnt);
	bo[now]=1;
	baoli(now+1,cnt+1);
	bo[now]=0;
}
//clear
void clear(){
	ans=INF;
	memset(bo,0,sizeof(bo));
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	
	c=read(),t=read();
	while(t--){
		input();
		floyed();
		baoli(1,0);
		cout<<ans<<'\n';
		clear();
		
	}
	return 0;
}

