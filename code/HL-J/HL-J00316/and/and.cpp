#include<bits/stdc++.h>

using namespace std;
const int N=1e5+10;
int n,m;
int a[N];
int ans;
void dfs(int u,int sum,int cnt){
	//if(u > n)return ;
	if(cnt >= m){
		ans = max(ans,sum);
		return ;
	}
	for(int i = u+1;i <= n;i++){
		int k;
		if(cnt==0)k = a[i];
		else k = sum&a[i];
		dfs(i,k,cnt+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n>>m;
	for(int i = 1;i <= n;i++){
		cin >>a[i];
	}
	dfs(0,0,0);
	cout <<ans;
	return 0;
}