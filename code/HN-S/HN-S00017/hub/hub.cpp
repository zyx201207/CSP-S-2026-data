#include<bits/stdc++.h>
using namespace std;
#define int long long
int id,t;
int n,k;
int u[100005];
int v[100005];
int c[100005];
int fa[100005];
int dis[15][15];
int findd(int x){
	return (x==fa[x]?x:fa[x]=findd(fa[x]));
}
void unionn(int x,int y){
	x=findd(x),y=findd(y);
	if(x!=y)fa[x]=y;
}
bool check(int x){
	if(__builtin_popcount(x)>k)return false;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		if((x>>(i-1))&1)c[i]=1;
		else c[i]=0;
	}
	for(int i=1;i<n;i++){
		if(c[u[i]]&&c[v[i]]){
			unionn(u[i],v[i]);
		}
	}
	set<int> st;
	for(int i=1;i<=n;i++){
		if(c[i]){
			st.insert(findd(i));
		}
	}return st.size()<=2;
}
int solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<n;i++){
		dis[u[i]][v[i]]=dis[v[i]][u[i]]=1;
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
		// cout<<c[i]<<' ';
		int sum=1e18;
		for(int j=1;j<=n;j++){
			if(c[j])sum=min(sum,dis[i][j]);
			// cout<<dis[i][j]<<" ";
		}ans=max(ans,sum);
		// cout<<"\n";
	}
	// cout<<ans<<"\n";
	// if(ans==0)cout<<"aa:"<<'\n';
	return ans;
}
signed main(){
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>id>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>u[i]>>v[i];
		int ans=1e18;
		for(int i=0;i<(1<<n);i++){
			if(check(i)){
				// cout<<i<<"\n";
				ans=min(ans,solve());
			}
		}cout<<ans<<"\n";
	}
  return 0;
}
//g++ -o hub -O2 -std=c++14 -g -Wall -Wextra -fsanitize=address,undefined hub.cpp
