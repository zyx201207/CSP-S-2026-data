#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[622222];
long long ans=-1;
void dfs(long long u,long long s,long long as){
	if(u>n){
		if(s==m){
			ans=max(ans,as);
			//cout<<as<<'\n';
		}
		return;
	}
	if(s>=m){
		return;
	}
	if(as==-214444){
		dfs(u+1,s+1,(as&a[u]));
	}else{
		dfs(u+1,s+1,a[u]);
	}

	dfs(u+1,s,as);

}
long long xx=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxx=-122222;
	long long sum;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sum=a[1];
	for(long long i=1;i<=n;i++){
		sum=(sum&a[i]);
	}
	if(m==1){
		cout<<maxx;
	}else if(m==n){
		cout<<sum;
	}else if(m==2){
		long long mx=-12222;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				mx=max(mx,(a[i]&a[j]));
			}
		}
		cout<<mx;
	}else if(m==n-1){
		long long anss=-12222;
		sum=a[2];
		for(long long i=2;i<=n;i++){
			sum=(sum&a[i]);
		}
		anss=max(anss,sum);
		for(long long i=2;i<=n;i++){
			sum=a[1];
			for(long long j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				sum=(sum&a[i]);
			}
			anss=max(anss,sum);
		}
		cout<<anss;
	}else{
		dfs(1,0,-214444);
		cout<<ans;
	}
	return 0;
}
