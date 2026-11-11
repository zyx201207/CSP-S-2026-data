#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,q=2e30,l;
bool p[200005];
void dfs(int x,int u){
	if(x>=m){
		ans=max(ans,u);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(u==0){
			u=2e30;
		}
		if(!p[i]){
			p[i]=true;
			dfs(x+1,u&a[i]);
			p[i]=false;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q&=a[i];
		l=max(l,a[i]); 
	}
	if(n==m){
		cout<<q;
		return 0;
	}
	if(m==1){
		cout<<l;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
