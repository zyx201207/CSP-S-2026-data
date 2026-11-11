#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE 1
#define duoce 1
typedef long long ll;
const int N=5000+5;
inline ll read(){
	ll ret=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
void write(ll x){
	if(x<0){
		putchar('-'),x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void solve();
int c;
int main(){
	if(ONLINE_JUDGE){
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
	}
	else{
		freopen("migrate2.in","r",stdin);
	}
	int t=1;
	if(duoce)c=read(),t=read();
	while(t--)solve();
}
int n;
ll d,x[N];
ll dis[N][N],cnt[N][N];
bool is[N][N];
void solve(){
	n=read(),d=read();
	for(int i=1;i<=n;i++)x[i]=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dis[i][j]=0x3f3f3f3f3f3f3f3f,cnt[i][j]=0,is[i][j]=0;
	}
	queue<int>q;
	for(int u=1;u<=n;u++){
		q.push(u);
		dis[u][u]=0;
		cnt[u][u]=1;
		is[u][u]=1;
		while(q.size()){
			int f=q.front();
			q.pop();
			//cout<<"f:"<<f<<endl;
			for(int i=f+1;i<=n;i++){
				//cout<<"debug:"<<x[f]<<" "<<d<<" "<<x[i]<<endl;
				if(x[f]+d<x[i])continue;
				 
				if(dis[u][i]>dis[u][f]+1){
					dis[u][i]=dis[u][f]+1;
					cnt[u][i]=cnt[u][f];
					//cout<<"f:"<<f<<"gengxin"<<i<<" "<<cnt[u][f]<<" "<<dis[u][i]<<"\n"; 
					q.push(i);
					is[f][i]=1;
				}
				else if(!is[f][i]&&dis[u][i]==dis[u][f]+1){
					//cout<<i<<"->"<<f<<":duo"<<dis[u][f]+1<<"\n"; 
					cnt[u][i]+=cnt[u][f];
					q.push(i);
					is[f][i]=1;
				}
				
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<u<<"-"<<i<<":"<<cnt[u][i]<<" "<<dis[u][i]<<endl;
//		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2)ans++;
		}
	}
	write(ans);
	putchar('\n');
	return;
}
