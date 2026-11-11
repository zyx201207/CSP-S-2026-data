#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int maxx;
void dfs(long long k,int sum,int now){
	if(k==m){
		maxx=max(maxx,sum);
		return; 
	}
	for(int i=now+1;i<=n;i++){
		if(k==0)dfs(k+1,a[i],i);
		else dfs(k+1,a[i]&sum,i);
	}
}
int main(){
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,a[1],0);
	cout<<maxx;
	return 0;
} 
/*

*/
