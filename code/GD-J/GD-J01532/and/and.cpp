#include <bits/stdc++.h>
using namespace std;

long long ans;

void dfs(long long a[],long long n,long long m,long long now,long long cnt,long long b[]){
	if(cnt==m){
		long long sum=b[1];
		for(int i=1;i<=m;i++) sum&=b[i];
		ans=max(ans,sum);
		return;
	}
	for(int i=now+1;i<=n;i++){
		b[cnt+1]=a[i];
		dfs(a,n,m,i,cnt+1,b);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++) cin>>a[i];
	long long b[n+5];
	memset(b,0,sizeof(b));
	dfs(a,n,m,0,0,b); 
	cout<<ans;
	return 0;
} 
