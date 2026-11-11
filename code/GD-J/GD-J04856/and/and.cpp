#include<bits/stdc++.h>
using namespace std;
int n,m;
int e[200005];
int ma;
void dfs(int now,int used,int res){
	if(used==m){
		ma=max(ma,res);
		return;
	}
	if(now>=n)return;
	for(int i=now+1;i<=n-m+used+1;i++){
		dfs(i,used+1,res&e[i]);
	} 
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//BAOLI
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>e[i];
	}
	for(int i=1;i<=n-m+1;i++){
		dfs(i,1,e[i]);
	}
	cout<<ma;
	return 0;
}
