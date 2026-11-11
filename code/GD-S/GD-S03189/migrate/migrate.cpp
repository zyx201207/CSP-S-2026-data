#include<bits/stdc++.h>
using namespace std;
long long n,d;
int c,t;
long long x[2000005];
long long a[5000][5000];
void dfs(int po,int len){
	if(po>n) return ;
	if(po!=1&&po<=n){
		a[po][len]++;
	}
	for(int i=po+1;i<=n;i++){
		if(x[i]-x[po]<=d){
			dfs(i,len+1);
		}
		else break;
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			dfs(i,0);
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==2) ans++; 
			}
		}
		cout<<ans-1<<'\n';
	}
	return 0;
} 
