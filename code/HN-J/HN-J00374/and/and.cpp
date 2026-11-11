#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[20005];
int dfs(int ans,int now,int y){
	if(now==m){
		return ans;
	}
	if(y==n+1){
		return 1;
	}
	if(ans==0){
		return 1;
	}
	return max(dfs(ans,now,y+1),dfs((ans&a[y]),now+1,y+1));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(pow(2,30)-1,0,1);
	return 0;
}
