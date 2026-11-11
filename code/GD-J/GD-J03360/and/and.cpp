#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,ans,a[N];
void dfs(int pos,int sum,int k){
	if(k==m){
		ans=max(ans,sum);
		return ;
	}
	if(pos>n){
		return ;
	}
	if(n-pos+1<m-k){
		return ;
	}
	dfs(pos+1,sum&a[pos],k+1);
	dfs(pos+1,sum,k);
	return ;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		swap(a[1],a[i]);
		dfs(2,a[1],1);
	}
	cout<<ans;
	return 0;
}
