#include<bits/stdc++.h>
using namespace std;
int n,d,x[2000005];
bool mayf[14][14];
bool XZA(){
	int jianjv=x[2]-x[1];
	for(int i=2;i<=n;i++){
		if(x[i]-x[i-1]!=jianjv){
			return 0;
		}
		return 1;
	}
}
void dfs(int start,int end,int now){
	if(now==end){
		mayf[start][end]=1;
	}else{
		for(int i=now+1;i<=end;i++){
			if(x[i]-x[now]<=d){
				dfs(start,end,i);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(XZA()){
			int jj=x[2]-x[1];
			if(2*jj>=d&&3*jj<d){
				cout<<n-2<<"\n";
			}else{
				cout<<0<<"\n";
			}
		}else{
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					dfs(i,j,i);
				}
			}
			int ans=0;
			for(int i=1;i<n-2;i++){
				for(int j=i+2;j<=n;j++){
					if(mayf[i][j])ans++; 
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}

