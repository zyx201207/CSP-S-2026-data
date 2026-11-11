#include<bits/stdc++.h>
using namespace std;
int a[293242];int n,m;
long long k=0;
int dfs(int st,int gt){
	if(gt==m){
		return a[st];
	}
	for(int i=st+1;i<=n;i++){
		return (a[st]&dfs(i,gt+1));
}}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int g=dfs(i,1);
		if(k<=g){
			k=g;
		}
			
			
	}
	cout<<k;
	return 0;
}
