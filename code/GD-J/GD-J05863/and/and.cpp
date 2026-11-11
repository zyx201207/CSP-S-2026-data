#include <bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long>a(5*100000);
long long ans=0;

void dfs(int step,long long las_ans,int p){
	for(int i=p+1;i<=n-(m-step-1);i++){
		if(step+1!=m){
			dfs((step+1),(las_ans&a[i]),i);
		}else{
			ans=max(ans,(las_ans&a[i]));
		}
	}
	return;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m;i++){
		dfs(1,a[i],i);
	}
	cout<<ans;
	return 0;
}
