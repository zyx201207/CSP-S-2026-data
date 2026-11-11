#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],ans;
void dfs(int k,int sum){
	if(k==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=k+1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			dfs(k+1,sum&a[i]);
			b[i]=0;
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
	for(int i=1;i<=n;i++){	
		b[i]=1;
		dfs(1,a[i]);
		b[i]=2;
	}
	cout<<ans;
	return 0;
}
