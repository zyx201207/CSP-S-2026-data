#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
long long read(){
	long long t;
	scanf("%lld",&t);
	return t;
} 
long long a[maxn];
vector<int> e[maxn];
long long ds[maxn];
long long dp[maxn]; 
long long n,d;
int c,t;
void dfs(int u,int fa){
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==fa) continue;
		if(ds[v]>ds[u]+1){
			ds[v]=ds[u]+1;
			dp[v]=1;
		} 
		else if(ds[v]==ds[u]+1){
			dp[v]++;
		}
		dfs(v,u);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		if(c==11 || c==12){
			int T=a[2]-a[1];
			if(d>=2*T && d<3*T){
				cout<<n-3<<endl;
			} 
			else{
				cout<<0<<endl;
			}
			continue;
		}
		memset(e,0,sizeof(e));
		for(int i=1;i<=n;i++){
			if(a[i]-a[i-1]<=d){
				e[i-1].push_back(i);
				e[i].push_back(i-1);
			}
		}
		long long num;
		for(int i=1;i<=n;i++){
			memset(ds,0x3f,sizeof(ds));
			memset(dp,0,sizeof(dp)); 
			ds[i]=0;
			dfs(i,0); 
			for(int j=1;j<=n;j++){
				if(dp[j]==2 && j!=i){
					num++;
				}
			}
		}
		cout<<num/2<<endl;
	}
	return 0;
}
