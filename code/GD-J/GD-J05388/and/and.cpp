#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,mx,sum;
void dfs(int k,int cnt,int nans){
	if(cnt==m){
		ans=max(ans,nans);
		return;
	} 
	if(k>n)return;
	if(cnt==0){
		dfs(k+1,1,a[k]);
		dfs(k+1,cnt,nans);
	}
	else{
		dfs(k+1,cnt+1,(nans&a[k]));
		dfs(k+1,cnt,nans);
	} 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
	}
	sum=a[1];
	for(int i=2;i<=n;i++){
		sum&=a[i];
	}
	if(m==1){
		cout<<mx;
		return 0; 
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
