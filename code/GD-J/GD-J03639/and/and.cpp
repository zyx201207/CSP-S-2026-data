#include <bits/stdc++.h>
using namespace std;
int n,m,maxn=-1;
int a[500005];
void dfs(int x,int cnt,int sum){
	if(cnt>=m){
		maxn=max(sum,maxn);
		return;
	}
	if(x>n) return;
	dfs(x+1,cnt+1,(sum&a[x]));
	dfs(x+1,cnt,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m; 
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i+1,1,a[i]);
	}
	cout<<maxn;
	return 0;
}
