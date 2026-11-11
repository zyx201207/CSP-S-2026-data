#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
void dfs(int x,int sum,int l){
	if(x==m){
		ans=max(ans,sum);
		return;
	}
	if(x>m)return;
	if(n-l+x<m)return;
	for(int i=l+1;i<=n;i++){
		if(x==0){
			dfs(x+1,a[i],i);
			dfs(x,sum,i);
		}else{
			dfs(x+1,(sum&a[i]),i);
			dfs(x,sum,i);
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
	dfs(0,0,0);
	cout<<ans;
	cout<<endl;
	return 0;
}
