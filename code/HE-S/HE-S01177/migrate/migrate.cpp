#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int128 __int128
#define gc getchar()
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=2e6+10;
int rd(){
	int x=0,f=1;char c=gc;
	for(;!isdigit(c);c=gc)if(c=='-')f=-1;
	for(;isdigit(c);x=x*10+c-'0',c=gc);
	return x*f;
}
ll rdll(){
	ll x=0,f=1;char c=gc;
	for(;!isdigit(c);c=gc)if(c=='-')f=-1;
	for(;isdigit(c);x=x*10+c-'0',c=gc);
	return x*f;
}
ll absll(ll a){
	if(a<0)return -a;
	else return a;
}
int c,t;
int n;ll d,x[N];
ll dis[510][510];int cnt=0;
void dfs(int now,int fal,int tot,int p){
	if(now==fal&&tot==p){
		cnt++;
		return;
	}
	if(now>n)return;
	for(int i=now+1;i<=n;i++){
		if(absll(x[now]-x[i])<=d){
			dfs(i,fal,tot+1,p);
		}
	}
}
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(absll(x[i]-x[j])<=d){
				dis[i][j]=1;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cnt=0;
			dfs(i,j,0,dis[i][j]);
			if(cnt==2)ans++;
		}
	}
	cout<<ans<<"\n";
}
void solve(){
	n=rd();d=rdll();
	for(int i=1;i<=n;i++)x[i]=rdll();
	if(n<=500){solve1();return;} 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd(),t=rd();
	while(t--){
		solve();
	}
	return 0;
}

