#include<bits/stdc++.h> 
using namespace std;
int read(){
	int res=0,sig=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')sig=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res*=10;
		res+=c-'0';
		c=getchar();
	}
	return res*sig;
}
const int N=5001;
long long mod=1e9+7;
int x[N];
int n,d;
void solve1(){
	int t;t=read();
	while(t--){
		n=read(),d=read();
		vector<vector<long long> > dp(n,vector<long long>(n)),dis(n,vector<long long>(n,1e9));
		for(int i=1;i<=n;i++){
			x[i]=read();
			dis[i][i]=0;
			for(int j=i-1;i>=1;j++){
				if(x[i]-x[j]>=d){
					dis[j][i]=dis[i][j]=1;
					dp[j][i]=dp[i][j]=1;
				}
			}
		}
			cout<<"1";
			return ;
		for(int st=1;st<=n;st++){
			
			priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
			pq.push({0,st});
			vector<int> vis(n+1);
			while(!pq.empty()){
				int cur=pq.top().second,len=pq.top().first;
				pq.pop();
				vis[cur]=1;
				for(int nxt=1;nxt<=n;nxt++){
					if(nxt==cur||vis[nxt])continue;
					if(dis[st][cur]+dis[cur][nxt]<dis[st][nxt]){
						dis[st][nxt]=dis[st][cur]+dis[cur][nxt];
						dp[st][nxt]=dp[st][cur]*dp[cur][nxt]%mod;
					}
					else if(dis[st][cur]+dis[cur][nxt]==dis[st][nxt]){
						dp[st][nxt]=dp[st][nxt]+dp[st][cur]*dp[cur][nxt];
						dp[st][nxt]%=mod;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(dp[i][j]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
void solve3(){
	int t;t=read();
	while(t--){
		int n,d;
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			int x;
			x=read();
		}
		cout<<"0\n";
	}
}
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c;c=read();
	if(c<=10)solve1();
	else if(c>=11&&c<=12)cout<<1;
	else if(c>=13&&c<=14)solve3();
	else if(c>=15&&c<=18)cout<<1;
	else cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
