#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n,m;
long long maxn=0;
void dfs(int deep,int d,long long ans){
	if(deep==m){
		maxn=max(maxn,ans);
		return;
	}
	for(int i=d;i<n;i++){
		dfs(deep+1,i+1,ans&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		dfs(1,i+1,a[i]);
	}
	cout<<maxn;
	return 0;
} 

