#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
long long ans=-1;
long long n,m;
void dfs(long long now,int step,int st){
	if(step==m){
		ans=max(ans,now);
		return;
	}
	for(int i=st;i<=n;i++){
		dfs((now&a[i]),step+1,i+1);
	}	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(a[i],1,i+1);
	}
	cout<<ans;
	
	return 0;
} 



