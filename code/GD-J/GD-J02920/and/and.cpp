#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[10000005],m,ans,l;
void dfs(int i,int sum,int l){
	if(i==n+1||l>=m){
		ans=max(ans,sum);
	}else{
		if(n-i<=m-l){
			dfs(i+1,sum&a[i],l+1);
		}else{
			dfs(i+1,sum&a[i],l+1);
			dfs(i+1,sum,l);
		}
	}
}
main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout); 
	cin>>n>>m;
	m-=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		dfs(i+1,a[i],0);
	}
	cout<<ans;
} 
