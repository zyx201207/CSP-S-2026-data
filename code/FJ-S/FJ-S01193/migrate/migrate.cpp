#include <bits/stdc++.h>
using namespace std;
long long a[2000005];
long long n,d;
long long cnt;
long long fast;
void dfs(long long l,long long r,long long num){
	if(num>fast){
		return;
	}
	if(num==fast&&l!=r){
		return;
	}
	if(l==r){
		if(num==fast){
			cnt++;
		}
		if(num<fast){
			fast=num;
			cnt=1;
		}
		return;
	}
	for(long long i=l+1;i<=r;i++){
		if(a[i]-a[l]<=d){
			dfs(i,r,num+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				fast=INT_MAX;
				cnt=0;
				dfs(i,j,0);
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}