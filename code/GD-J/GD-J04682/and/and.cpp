#include<bits/stdc++.h>
using namespace std;
const int N = 2E5+5;
int a[N];
int f[N];
int n,m,ans;
void dfs(int x,int ch,int num){
	if(x == n+1){
		if(ch == m){
			ans = max(ans,num);
		}
		return;
	}
	dfs(x+1,ch,num);
	dfs(x+1,ch+1,num&a[x]);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	dfs(1,0,-1);
	cout<<ans;
}
