#include<bits/stdc++.h>
using namespace std;
int t,n,d,x[2000006],ans,e,cnt;
int dfs(int a,int b){
		if(b>=e){
			return ;
		}
	
}
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		} 
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				e=j;
				if(x[j]-x[i]<=d){
					continue;
				}
				if(dfs(i,j)==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
}
