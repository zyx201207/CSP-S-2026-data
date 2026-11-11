#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
long long a[200010];
void dfs(int k,long la,long long sum){
	if(k>m){
		ans=max(ans,sum);
	}else{
		if(k==1){
			for(int i=1;i<=n;i++){
				dfs(2,i,a[i]);
			}
		}
		else for(int i=la+1;i<=n;i++){
			if(a[i]==0)continue;
			dfs(k+1,i,sum&a[i]);
		}
	}
}
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
}
