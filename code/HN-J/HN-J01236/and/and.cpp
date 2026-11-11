#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
int m;
int ans;
int a[N];
int st[N];
void dfs(int x,int maxi){
	if(x==m){
		ans=max(ans,maxi);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!st[i]){
			st[i]=1;
			dfs(x+1,maxi&a[i]);
			st[i]=0;
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
	for(int i=1;i<=n;i++){
		st[i]=1;
		dfs(1,a[i]);
		st[i]=0;
	}
	cout<<ans;
	return 0;
}
