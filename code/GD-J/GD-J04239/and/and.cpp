#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0;//求最大值 
vector<long long> number;
vector<bool> vis;
void dfs(long long x,int can,int ip){
	if(can==0){
		ans=max(ans,x);
		return;
	}
	for(int i=ip;i<n;i++){
		if(vis[i]==1)continue;
		vis[i]=1;
		dfs((x & number[i]),can-1,ip);
		vis[i]=0;
	}
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	number.resize(n+5);
	for(int i=0;i<n;i++){
		cin>>number[i];
	}
	vis.resize(n+5,0);
	for(int i=0;i<n;i++){
		vis[i]=1;
		dfs(number[i],m-1,i);//枚举以当前点为起点的选择方案 
		vis[i]=0;
	}
	cout<<ans;
	cout<<flush;
	return 0;
}
