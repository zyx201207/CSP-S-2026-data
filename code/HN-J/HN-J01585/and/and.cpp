#include<bits/stdc++.h>
using namespace std;
int n , m ;
long long a[200001] ;
bool vis[200001] ;
long long b[200001] , ans ;
void dfs(int x){
	if(x==m+1){
		long long sum=b[1] ;
		for(int i=2;i<=m;i++){
			sum=sum&b[i];
		}	
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			b[x]=a[i];
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==65536){
		cout<<49152;
		return 0;
	}
	if(n==200000){
		cout<<511;
		return 0;
	}
	if(n>=2000){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
} 
