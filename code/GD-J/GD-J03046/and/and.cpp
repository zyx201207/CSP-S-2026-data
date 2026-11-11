#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int mx=-1e9;
bool vis[2000005];
inline void dfs(int now,int cnt){
	if(now>m){
		mx=max(mx,cnt);
	}
	else{
		for(int i=1;i<=n;i++){
			if(now==1)cnt=a[i];
			if(vis[i])continue;
			else{
				vis[i]=1;
				dfs(now+1,cnt&a[i]);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1);
	cout<<mx;
	
	return 0;
}
