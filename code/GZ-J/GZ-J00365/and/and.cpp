//GZ-J00365 ºî¶÷Í® 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n,m;
int a[N],b[N];
int ans;
void check(){
	int sum = b[1];
	for(int i = 2;i <= m;i++){
		sum = sum&b[i];
	}
	ans = max(ans,sum);
}
void dfs(int k,int start){
	if(k==m+1){
		check();
		return;
	}
	for(int i = start;i <= n;i++){
		b[k] = a[i];
		dfs(k+1,i+1);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
