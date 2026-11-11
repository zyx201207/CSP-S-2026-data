#include<bits/stdc++.h>
using namespace std;
int n,maxx = -1e8,m,a[200005];
void dfs(int x,int i,int sum){
	if(sum)
		sum = sum&a[i];
	else 
		sum = a[i];
	if(x == m){
		maxx = max(maxx,sum);
		return;
	}
	for(int j = i+1;j <= n;j++)
		dfs(x+1,j,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m; 
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}dfs(0,0,0);
	cout << maxx;
	return 0;
}
