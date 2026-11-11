#include<bits/stdc++.h>
using namespace std;
int n,m,maxa;
int a[200005];
void dfs(int id,int sum,int x){
	if(x==m){
		maxa=max(maxa,sum);
		return;
	}
	if(id>n){
		return;
	}
	dfs(id+1,sum&a[id],x+1);
	dfs(id+1,sum,x);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
//	for(int i=1;i<=n;i++){
//		dfs(i+1,a[i],1);
//	}
	cout<<a[m];
	return 0;
}
