#include<bits/stdc++.h>
using namespace std;
int ret=0;
vector<int> a;
int n, m;
void dfs(int cnt, int step, int aa){
	if(aa==0)return;
	if(cnt==m){
		ret=max(ret, aa);
		return;
	}
	if(step>=n)return;
	dfs(cnt, step+1, aa);
	dfs(cnt+1, step+1, aa&a[step]);
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	int all=0x7fffffff;
	a.resize(n+1);
	for(int i=0; i<n; i++){
		cin>>a[i];
		all&=a[i];
	}
	if(m==n){
		cout<<all;
		return 0;
	}
	dfs(0, 0, 0x7fffffff);
	cout<<ret;
	return 0;
}
