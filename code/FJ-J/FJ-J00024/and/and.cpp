#include<bits/stdc++.h>
using namespace std;
long long n,m,maxa;
long long a[2*114514];
bool vis[2*114514];
long long dfsans,sum;
void dfs(long long s){
	if(s>m){
		dfsans=max(dfsans,sum);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			sum&=a[i];
			vis[i]=1;
			dfs(s+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(n<=20){
		dfs(1);
		cout<<sum;
	}else if(m==2){
		long long ans=0;
		for(long long i=1;i<n;i++){
			for(long long j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(m==n){
		long long ans=a[1];
		for(long long i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else{
		cout<<maxa;
	}
	return 0;
}
