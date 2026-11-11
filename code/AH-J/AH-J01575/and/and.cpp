#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tongji,n,m,a[200005],vmax=-2147483647,vmin=2147483647,ans=2147483647;
bool flag=true;
void dfs(int u,int check,ll and1){
	if(check==m){
		ans=max(ans,and1);
		return;
	}
	if(u==n+1){
		if(check==m){
			ans=max(ans,and1);
		}
		return;
	}
	dfs(u+1,check,and1);
	if(check<m)dfs(u+1,check+1,and1&a[u]);
}
signed main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans&=a[i];
		vmax=max(vmax,a[i]);
		vmax=min(vmin,a[i]);
		if(a[i]!=i-1)flag=false;
	}
	if(m==n-1){
		ans=2147483647;
		for(int i=1;i<=n;i++)
			if(a[i]!=vmin&&tongji==0)tongji++,ans&=a[i];
	}else if(m==1){
		cout<<vmax;
		return 0;
	}else if(!flag&&m!=n)ans=-1,dfs(1,0,2147483647);
	else if(m!=n){
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--)
			ans&=a[i];
	}
	cout<<ans;
	return 0;
} 
//Trick||Treat!
