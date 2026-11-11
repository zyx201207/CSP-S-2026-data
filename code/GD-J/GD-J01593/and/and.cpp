#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200100];
long long ans=0;
int vis[200100];
vector<int>o;
void dfs(int last,int siz){
	if(siz==m){
		long long y=o[0];
		for(int i=1;i<m;i++){
			y&=o[i];
		}
		ans=max(ans,y);
		o.clear();
		return; 
	}
	for(int i=last+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			o.push_back(a[i]);
			dfs(last+1,siz+1);
			vis[i]=0;
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
	dfs(0,0);
	cout<<ans;
	return 0;
}
