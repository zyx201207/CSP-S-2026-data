#include<bits/stdc++.h>
using namespace std;
const int xy=222222;
int n,m,u[xy],s,ma=-1e9;
bool v[xy];
void dfs(int x,int y){
	if(y==m){
		ma=max(ma,x);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			dfs((x & u[i]),y+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>u[i];
	if(m==1){
		for(int i=1;i<=n;i++)ma=max(ma,u[i]);
		cout<<ma;
		return 0;
	}else if(m==n){
		s=u[1];
		for(int i=2;i<=n;i++)s=(s & u[i]);
		cout<<s;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					s=(u[i] & u[j]);
					ma=max(s,ma);
				}
			}
		}
		cout<<ma;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			v[i]=1;
			dfs(u[i],1);
			v[i]=0;
		}
		cout<<ma;
		return 0;
	}
	return 0;
}
