#include <bits/stdc++.h>
using namespace std;

int n;
int ans,a[25];

void dfs(int sum ,int step){
	if(sum>n){
		ans=max(ans,sum);
		return;
	}
	dfs(sum+1,step);
	dfs(sum+1,a[step]);
}
ios::synk_with_stdio(false);

int main(){
	
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	
	

	
	cin>>n;
	if(n>0){
		
		int ans=n;
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	
	dfs(1,0);
	cout<< ans<<"/n" ;
	return 0;
}





















