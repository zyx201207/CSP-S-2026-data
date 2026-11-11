#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool v[200005];
int fw[14];
int mx=-1;
void dfs(int s,int res){
	if(s==m+1){
		mx=max(mx,res);
		return;
	}
	for(int i=1;i<=n-m+s;i++){
		if(!v[i]){
			v[i]=1;
			dfs(s+1,(res&a[i]));
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		dfs(1,a[i]);
	}
	cout<<mx;
	return 0;
}
