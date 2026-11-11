#include<bits/stdc++.h>
using namespace std;
int n,m,a[2005] ,ans=0;
bool v[2005];
void dfs(int c,int x){
	if(c==m){
		ans=max(x,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			if(c==0){
				dfs(c+1,a[i]);
			}
			else dfs(c+1,x&a[i]);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
