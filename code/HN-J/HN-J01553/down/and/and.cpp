#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx=-1e9;
void dfs(long long t,long long op,long long ans){
	if(op>m){
		maxx=max(maxx,ans);
	}
	if(t>n){
		return ;
	}
	dfs(t+1,op+1,ans&a[t]);
	dfs(t+1,op,ans);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	if(n<=20){
		for(long long i=1;i<=n;i++){
			dfs(i,1,a[i]);
		}
	}
	if(m==2){
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				long long x=a[i]&a[j];
				maxx=max(maxx,x);
			}
		}
	}
	long long ans=a[1];
	for(long long i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<max(ans,maxx);
	return 0;
}

