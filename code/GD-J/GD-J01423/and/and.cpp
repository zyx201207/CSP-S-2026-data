#include<bits/stdc++.h>

using namespace std;
const int N=200005,INF=(1<<30)+5;
long long a[N],top[N],maxa=0;
int n,m,ans=0;
void dfs(int u,int ne,int res){
	//cout<<u<<" "<<ne<<" "<<res<<"\n";
	if(n-u+1<=ne){
		if(res==0)res=a[u];
		for(int i=u;i<=n;i++){
			res=res&a[i];	
		}
		ans=max(ans,res);
		return ;
	}
	if(ne<=0){
		ans=max(ans,res);
		return ;
	}
	
	if(res==0){
		dfs(u+1,ne-1,a[u]);
	}else dfs(u+1,ne-1,(res&a[u]));
	
	dfs(u+1,ne,res);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(a[i],maxa);
		/*int res=1;
		while(a>=res){
			res=res<<1;
		}
		top[i]=res-1;*/
	}
	
	if(m==1){
		cout<<maxa;
		return 0;
	} 
	if(m==n){
		int res=a[1];
		for(int i=2;i<=n;i++){
			res=(a[i]&res);
		}
		cout<<res;
		return 0;
	} 
	dfs(1,m,0);
	cout<<ans;
	return 0;
}
