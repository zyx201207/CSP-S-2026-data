#include<bits/stdc++.h>
using namespace std;
const int maxn=200090;
int n,m;int a[maxn];bool fa=1,fb;int ans=0;int vis[maxn];
bool cmp1(int x,int y){
	return x>y;
}
void dfs(int i,int l,int s){
	if(l==m){
		ans=max(ans,s & a[i]);
		return;
	}
	for(int j=0;j<n;j++){
		if(vis[j]==0){
			vis[j]=1;
			dfs(j,l+1,s & a[i]);
			vis[j]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int cnt=1;
	for(int i=0;cnt<n;i++){
		cnt*=2;
	}
	if(cnt==n){
		fb=1;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];if((a[i]+1)%2!=0) fa=0;
		if(a[i]!=i) fb=0;
	}
	if(fa){
		sort(a,a+n,cmp1);
		cout<<a[m-1];
		return 0;
	}
	if(fb){
		int i=n-1;
		ans=a[i];
		for(int l=1;l<m;l++){
			ans=ans&a[i-l]; 
		}
		cout<<ans;
		return 0;
	}
	for(int i=0;i<n;i++){
		vis[i]=1;
		dfs(i,1,a[i]);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
