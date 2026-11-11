#include<bits/stdc++.h>
using namespace std;
int const N=2e5+10;
int n,m;
int ans=-1;
int an[N];
int js(int x,int y){
	int ax[31],ay[31],ans[31];
	for(int i=0;i<=30;i++){
		ax[i]=(x>>i)&1;
		ay[i]=(y>>i)&1;
		if(ax[i]&&ay[i]) ans[i]=1;
		else ans[i]=0;
	}
	int r=0;
	for(int i=0;i<=30;i++){
		r|=(ans[i]<<i);
	}
	return r;
}
int dfs(int depth,int val,int num){
	if(num>=m){
		ans=max(ans,val);
		return 0;
	}
	if(depth>n) return 0;
	int nv=val;
	if(nv==-1) nv=an[depth];
	else nv=js(nv,an[depth]);
	dfs(depth+1,val,num);
	dfs(depth+1,nv,num+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=-1;
	for(int i=1;i<=n;i++){
		cin>>an[i];
		mx=max(an[i],mx);
	}
	if(m==1){
		cout<<mx;
		return 0; 
	}
	if(m==n){
		int ans=an[1];
		for(int i=2;i<=n;i++) ans=js(ans,an[i]);
		cout<<ans;
		return 0;
	}
	dfs(1,-1,0); 
	cout<<ans;
	return 0;
}
