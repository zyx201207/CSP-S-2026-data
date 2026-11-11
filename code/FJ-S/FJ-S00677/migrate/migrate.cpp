#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n;
long long d,a[N];

//1~2
const long long maxn=1e16+6;
long long dp[10];int s[10];
void dfs(int p,int cnt){
	for(int i=p+1;i<=n;++i){
		if(d>=a[i]-a[p]){
			if(cnt+1<dp[i])dp[i]=cnt+1,s[i]=1;
			else if(cnt+1==dp[i])++s[i];
			dfs(i,cnt+1);
		}
	}
	
}
void sol1(){
	cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j)dp[j]=maxn,s[j]=0;
		dfs(i,0);
		for(int j=i+1;j<=n;++j){
			if(s[j]==2) ++ans;
		}
	}
	cout<<ans<<'\n';
}

vector<int> v[5005];
struct code{
	int e,st;	
};
int dis[5005],cnt[5005];
bool vis[5055];
void sol3(){
	cin>>n>>d;
	for(int i=1;i<=n;++i)cin>>a[i],v[i].clear();
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(a[j]-a[i]<=d){
				v[i].push_back(j);
			}else{
				break;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j)dis[j]=-1,vis[j]=0,cnt[j]=0;
		code h=(code){i,0};
		queue<code> q;q.push(h);
		while(!q.empty()){
			h=q.front();q.pop();
			if(vis[h.e]){
				if(h.st==dis[h.e])++cnt[h.e];
				continue;
			}
			vis[h.e]=1;
			dis[h.e]=h.st;
			cnt[h.e]=1;
			for(int j=0;j<v[h.e].size();++j){
				int g=v[h.e][j];
				//if(!vis[g]){
					q.push((code){g,h.st+1});
				//}else if(dis[g]==h.st+1)++cnt[g];
				
			}
		}
		for(int j=i+1;j<=n;++j){
			if(cnt[j]==2)++ans;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){//A:8pts
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;++i)cin>>a[i];
			long long ch=a[2]-a[1];
			long long m=d/ch;
			if(m+m>n||m<=1)cout<<0;
			else cout<<n+1-m-m;
			cout<<'\n';
		}
		return 0;	
	}
	if(c<=2){//8pts
		while(t--)sol1();
		return 0;
	}
//	if(c<=10){
		while(t--)sol3();
//		return 0;
//	}
	return 0;
} 
