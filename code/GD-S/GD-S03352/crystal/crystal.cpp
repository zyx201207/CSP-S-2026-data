#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000005];
int sum[100000005];
int maxn;
int x;
void dfs(int k){
	if(k==n+1){
		for(int i=1;i<=x;i++){
			maxn=max(maxn,sum[i]);
		}
		return;
	}
	for(int i=1;i<=m;i++){
		a[k]+=i;
		sum[a[k]]++;
		dfs(k+1);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=max(x,a[i]+m);
	}
	dfs(1);
	cout<<maxn+1;
	return 0; 
} 
