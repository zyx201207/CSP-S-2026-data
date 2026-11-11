#include <bits/stdc++.h>
using namespace std;
//container
int n,m;
long long ans=0;
long long a[200005];
//func
void dfs(int k,long long c,int t){
	if(k == m+1){
		ans = max(ans,c);
//		cout<<c<<"\n";
		return;
	}
	for(int i=t+1;i<=n;++i){
		dfs(k+1,c&a[i],i);
	}
}
//main
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	dfs(1,2147483647,0);//2147483647
	cout<<ans;
	return 0;
}

