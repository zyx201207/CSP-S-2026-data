#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long max1=INT_MIN;
void dfs(int b,int m,long long ans){
	if(m==0){
		max1=max(max1,ans);
		return;
	}
	for(int i=b;i<=n-m+1;i++){
		ans=ans&a[i];
		dfs(i+1,m-1,ans);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		dfs(i+1,m-1,a[i]);
	}
	cout<<max1;
	return 0;
}
