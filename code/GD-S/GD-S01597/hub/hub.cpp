#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N=1e6+5;

int c,n,m,T,k,x,y;
vector<int> a[N];
int v[N],v2[N],ans;
int d[305][305];


void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}
	return;
}

void run(int k,int p){
	v2[k]=1;
	for(auto i:a[k]){
		if(v[i]&&i!=p) run(i,k);
	}
	return;
}

bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++) v2[i]=0;
	for(int i=1;i<=n;i++){
		if(v[i]&&!v2[i]){
			cnt++;run(i,0);
		}
	}
	return (cnt<=2);
}

int cal(){
	int ret=0;
	for(int i=1;i<=n;i++){
		int mi=1e9;
		if(!v[i]){
			for(int j=1;j<=n;j++){
				if(v[j]) mi=min(mi,d[i][j]);
			}
		}
		else mi=0;
		ret=max(ret,mi);
	}
	return ret;
}

void dfs(int now,int cnt){
	if(now>n){
		if(cnt<k) return;
		if(check()){
			ans=min(ans,cal());
		}
		return;
	}
	if(cnt<k){
		v[now]=1;dfs(now+1,cnt+1);	
	}
	v[now]=0;dfs(now+1,cnt);
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			v[i]=0;d[i][i]=0;a[i].clear();
			for(int j=1;j<=n;j++) d[i][j]=1e9;
			d[i][i]=0;
		}
		for(int i=1;i<n;i++){
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
			d[x][y]=1;
			d[y][x]=1;
		}
		floyd();ans=1e9;
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
