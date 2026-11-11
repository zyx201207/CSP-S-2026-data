#include<bits/stdc++.h>
using namespace std;
bool mp[100000][100000];
int c,t,n,k,sum,x,y,ans=1e7;
int dfs(int x,int s){
	for(int j=1;j<=n;j++){
		sum+=mp[x][j];
	}
	if(sum==k){
		return s;
	}
	s++;
	for(int j=1;j<=n;j++){
		dfs(mp[x][j],s);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>x>>y;
			mp[x][y]=1;
			mp[y][x]=1;
		}
		for(int i=1;i<=n;i++){
			ans=min(dfs(i,1),ans);
		}
	} 
	cout<<ans;
	return 0;
}
 
