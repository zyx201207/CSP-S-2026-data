#include<bits/stdc++.h>
using namespace std;
int n,m,maxv;
int a[200001];
void dfs(int i,int k,int d){
	d&=a[i];
	if(d<=maxv)return;
	if(k==m){
		maxv=max(maxv,d);
		return;
	}
	i++; 
	for(;i<=n;i++){
		dfs(i,k+1,d);
	}
}
int main(){
	freopen("and.in","r",stdout);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)dfs(i,1,INT_MAX);
	cout<<maxv;
} 
