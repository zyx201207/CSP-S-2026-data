#include<bits/stdc++.h>
using namespace std;
int n,m;
long long num[200005];
long long ans=-1;
void dfs(long long sum,int k,int i){
	if(k==m+1){
		if(sum>ans){
			ans=sum;
		}
		return ;
	}
	for(;i<=n;i++){
		if(k==1){
			dfs(num[i],k+1,i+1);
		}else{
			dfs(sum&num[i],k+1,i+1);
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	dfs(0,1,1);
	cout<<ans;
	return 0;
}
