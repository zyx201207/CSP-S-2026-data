#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define pii pair<int,int>

const int N=1e6+10;

int dlh,T,n,k,dis[N],vis[N];
vector<int>v[N];
queue<int>q;

int lowbit(int x){
	return x&(-x); 
}

int Count(int x){
	int cnt=0;
	while(x){
		x-=lowbit(x);
		++cnt;
	}
	return cnt;
}

void dfs(int x,int pr,int X){
	vis[x]=1;
	for(auto y:v[x]){
		if(y==pr||(X&(1<<(y-1)))==0)continue;
		dfs(y,x,X); 
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	cin>>dlh>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y),v[y].push_back(x);
		}
		int ans=1e9;
		for(int i=0;i<(1<<n);i++){
			int Cnt=0;
			while(q.size())q.pop();
			if(Count(i)!=k)continue;
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))){
					dis[j]=0;
					q.push(j);	
				}else dis[j]=1e9;
				vis[j]=0;
			}
			for(int j=1;j<=n;j++){
				if(!vis[j]&&(i&(1<<(j-1)))){
					dfs(j,0,i);
					++Cnt;
				}
			}
			if(Cnt>2)continue;
			while(q.size()){
				int x=q.front();
				q.pop();
				vis[x]=1;
				for(auto y:v[x]){
					if(vis[y])continue;
					dis[y]=dis[x]+1;
					q.push(y);
				}
			}
			int res=0; 
			for(int j=1;j<=n;j++){
				res=max(res,dis[j]);
			}
			ans=min(ans,res);
		}
		cout<<ans<<"\n";
	}

	return 0;
}


