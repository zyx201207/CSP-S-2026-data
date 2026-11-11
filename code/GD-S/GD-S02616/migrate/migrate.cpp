#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500009],t,b[2009][2009],ans;
void dfs(ll start,ll i,ll end){
	if(i==end){
		b[start][end]++;
		return ;
	}
	if(a[i]+m<end){
		for(ll k=1;a[i+k]<=a[i]+m&&i+k<end;k++){
			dfs(start,i+k,end);
		}
	}else{
		dfs(start,end,end);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		ans=0;
		cin>>n>>m;
		for(ll i=0;i<n;i++){
			cin>>a[i];
		}
		for(ll i=0;i<n;i++){
			for(ll j=i+1;j<n;j++){
				dfs(i,i,j);
			}
		}
		for(ll i=0;i<n;i++){
			for(ll j=i+1;j<n;j++){
				if(b[i][j]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
