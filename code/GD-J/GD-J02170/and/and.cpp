#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int n,m,ans;
void dfs(int w,int d,int s){
	if(d==m){
		ans=max(s,ans);
		return ;
	}
	if(w>n) return ;
	dfs(w+1,d+1,((s==-1)?a[w]:s)&a[w]);
	dfs(w+1,d,s);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];	
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,-1);
	cout<<ans;
	return 0;
}

