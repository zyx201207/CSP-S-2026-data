#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int dfs(int num,int mx,int id){
	if(id>n){
		return mx;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=id;j++){
			mx=max(mx,a[i]);
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
	cout<<dfs(m,0,1);
	return 0;
} 
