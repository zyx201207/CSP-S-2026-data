#include <bits/stdc++.h>
using namespace std;
int n,m,a[20020],mymax=-1;
void dfs(int t,int x,int sum){
	if(t==m){
		if(sum>=mymax){
			mymax=sum&a[x];
		}
		return;
	}
	for(int i=x+1;i<=n;i++){
		dfs(t+1,i,sum&a[x]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(1,i,a[i]);
	}
	cout<<mymax;
	return 0;
}
