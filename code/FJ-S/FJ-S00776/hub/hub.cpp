#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+5;
int c,T;
int n,k,a,b,dis[N][N],ans;
bool book[N];

bool fl(vector<int> s){
	bool flag[N];
	int cnt=0;
	memset(flag,0,sizeof(flag));
	for(int i:s){
		if(flag[i]) continue;
		cnt++;
		if(cnt>2) return false;
		flag[i]=true;
		for(int j=1;j<=n;j++){
			if(dis[i][j]!=1e10 || dis[j][i]!=1e10)
				flag[j]=true;
		}
	}
	return cnt<=2;
}

void check(){
	vector<int> on;on.clear();
	int mx=0;
	for(int i=1;i<=n;i++){
		if(book[i])	
			on.push_back(i);
	}
	if(!fl(on)) return;
	for(int i=1;i<=n;i++){
		if(book[i]) continue;
		int num=1e10;
		for(int j:on){
			if(dis[i][j]==1e10 && dis[j][i]==dis[i][j])
				continue;
			if(i<j) num=min(num,dis[i][j]);
			else num=min(num,dis[j][i]);
		}
		mx=max(mx,num);
	}
	ans=min(ans,mx);
}

void dfs(int ct){
	if(ct==k){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]) continue;
		book[i]=true;
		dfs(ct+1);
		book[i]=false;
	}
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		ans=1e10;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=dis[j][i]=1e10;
		for(int i=1;i<n;i++){
			cin>>a>>b;
			if(a>b) swap(a,b);
			dis[a][b]=1;
		}
		for(int p=1;p<=n;p++){
			for(int i=1;i<n;i++){
				if(i==p) continue;
				for(int j=i+1;j<=n;j++){
					if(j==p) continue;
					int x=dis[i][p],y=dis[p][j];
					if(i>p) x=dis[p][i];
					if(j<p) y=dis[j][p];
					dis[i][j]=min(dis[i][j],x+y);	
				}				
			}			
		}	
		memset(book,0,sizeof(book));
		dfs(0);
		cout<<ans<<"\n";
	}
	return 0;
}
