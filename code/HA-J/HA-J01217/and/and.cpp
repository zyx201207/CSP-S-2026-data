#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int arr[200005];
void dfs(int x,int y,int z){
	if(z>m){
		ans=max(ans,x);
		return;
	}
	for(int i=y;i<n;i++){
		if(z==1) dfs(arr[i],i+1,z+1);
		else dfs(arr[i]&x,i+1,z+1);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	dfs(0,0,1);
	cout<<ans;
	return 0;
}

