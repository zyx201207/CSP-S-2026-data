#include<bits/stdc++.h>
using namespace std;
const long long N=1e6;
long long ans=-1,n,m,a[N];
void dfs(long long sum,long long c,long long w){//分别是数字，次数，和下标？ 
	if(c==m){ 
		ans=max(ans,sum);
		//cout<<sum<<' ';
		return;
	}
	if(w==n){
		return;
	}
	for(int i=w+1;i<=n;i++){
		dfs(sum&a[i],c+1,i);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}

	for(int i=1;i<=n;i++){
		dfs(a[i],1,i);
	}
	cout<<ans;
	return 0;
}
