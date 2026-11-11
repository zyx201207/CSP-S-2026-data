#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int mx = -1e4;
void dfs(int x,int num,int ans){
	if(x == n+1){
		if(num == m){
			mx = max(mx,ans);
		}
		else{
			return ;
		}
	}
	else if(num>=m){
		return ;
	}
	else{
		dfs(x+1,num,ans);
		dfs(x+1,num+1,ans&a[x]);
		return ;
	}
}
int main(){
	freopen(and.in,"stdin","r");
	freopen(and.out,"stdout","w");
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,146030928319);
	cout<<mx;
	return 0;
}
