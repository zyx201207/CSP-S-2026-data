#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx;
bool v[200005];
void dfs(int t,int s,long long ans){
	for(int i=t;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			if(s==0){
				dfs(t+1,s+1,a[i]);
				dfs(t+1,s,ans);
			}
			else{
				dfs(t+1,s+1,ans&a[i]);
				dfs(t+1,s,ans);
			}
			v[i]=0;
		}
	}
	if(s==m){
		maxx=max(maxx,ans);
		return;
	}
	if(t==n){
		return;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<maxx;
	return 0;
}
