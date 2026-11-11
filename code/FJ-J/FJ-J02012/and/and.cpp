#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long n,m;
long long ans;
long long flag1;
long long flag2;
long long flag3;
void dfs(long long k,long long num,long long p){
	if(p>n){
		if(k==m){
			ans=max(ans,num);
		}
		return;
	}
	if(k==0){
		dfs(k+1,a[p],p+1);
	}
	else{
		long long s=num&a[p];
		dfs(k+1,s,p+1);
	}
	dfs(k,num,p+1);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==n){
		flag2=1;
	}
	else if(m==1){
		flag1=1;
	}
	else if(m==2){
		flag3=1;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(flag1==1){
		long long maxx=-1e18;
		for(long long i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx<<endl;
	}
	else if(flag2==1){
		long long maxx=a[1];
		for(long long i=2;i<=n;i++){
			maxx=maxx&a[i];
		}
		cout<<maxx<<endl;
	}
	else if(flag3==1){
		long long maxx=-1e18;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(i==j)continue;
				else{
					long long b=a[i]&a[j];
					maxx=max(b,maxx);
				}
			}
		}
		cout<<maxx<<endl;
	}
	else{
		ans=0;
		dfs(0,0,1);
		cout<<ans<<endl;
	}
	return 0;
}
