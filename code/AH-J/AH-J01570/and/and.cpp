#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200008];
long long mx=-1e15,vmx=-1e15;
vector<int> vis,mxvis;
void dfs(int idx,int cnt){
	if(cnt==m){
		long long res=a[vis[0]];
		for(int i=1;i<vis.size();i++)
			res&=a[vis[i]];
		mx=max(mx,res);
		return ;
	}
	if(idx==n+1){
		
		return ;
	}
	vis.push_back(idx);
	dfs(idx+1,cnt+1);
	vis.pop_back();
	dfs(idx+1,cnt);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],vmx=max(vmx,a[i]);
	if(m==1){
		cout<<vmx;
		return 0;
	}else if(m==2){
		long long vmax=-1e15;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				vmax=max(vmax,a[i]&a[j]);
		cout<<vmax;
		return 0;
	}else if(m==n){
		long long res=a[1];
		for(int i=2;i<=n;i++)
			res&=a[i];
		cout<<res;
		return 0;
	}
	dfs(1,0);
	cout<<mx;
	return 0;
}
