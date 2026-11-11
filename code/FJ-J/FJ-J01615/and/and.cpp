#include<bits/stdc++.h>
using namespace std;

int n,m,a[200020];
int ans;
void dfs(int sum,int m,int k){
	if(m==0){
		ans=max(ans,sum);
		return;
	}
	if(k>=n){
		return;
	}
	for(int i=k+1;i<n;i++){
		dfs(sum&a[i],m-1,i);
	}
}

int main(){
//	freopen("and.in","w",stdout);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(INT_MAX,m,-1);
	cout<<ans;
	return 0;           
}