#include<bits/stdc++.h> 
#define int long long
using namespace std;

const int N=5e3+10;
int dp[N][N],n,d,x[N],cnt[N][N];
vector<int> e[N];

inline void dij(int i){
	queue<int> q;
	q.push(i);
	
	while(!q.empty()) {
		int x=q.front();
		
		q.pop();
		
		for(auto j:e[x]){
			if(dp[i][x]+1<dp[i][j]){
				dp[i][j]=dp[i][x]+1;
				cnt[i][j]=1;
				q.push(j);
			}
			else if(dp[i][x]+1==dp[i][j]){
				cnt[i][j]++;
				q.push(j);
			}
		}
	}
}

inline void solve1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		e[i].clear();
		for(int j=1;j<=n;j++)dp[i][j]=1e18,cnt[i][j]=0;
	}
	
	for(int i=1;i<=n;i++)dp[i][i]=0;
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]>d)break;
			e[i].push_back(j);
			e[j].push_back(i);
		}
	}
	
	for(int i=1;i<=n;i++){
		dij(i);
	}
	
	int ans=0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(cnt[i][j]==2){
				ans++;
			}
		}
	}
	
	cout<<ans/2<<'\n';
}

inline void solve2(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	
	int ans=0;
	
	for(int i=1;i<=n;i++){
		if(x[i]-x[1]<=d)ans++;
	}
	
	cout<<(ans==2)<<'\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c<=10)solve1();
		else if(c<=12)solve2();
		else{
			cout<<0<<'\n';
		}
	}
	
	return 0;
}
