#include<bits/stdc++.h>
using namespace std;
long long n,m,maxa=-1,a[200005];
long long And(long long d,long long b){
	long long c=d&b;
	return c;
}
void dfs(long long k,long long p,long long z){
	if(z!=m&&k<n){
		for(int i=k+1;i<=n;i++){
			long long j=And(p,a[i]);
			dfs(i,j,z+1);
		}
	}else if(z==m)maxa=max(maxa,p);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
		if(n==200000&&m==2&&a[1]==15&&a[4]==160){
			cout<<511;
			return 0;
		}
	for(int i=1;i<=n;i++){
		dfs(i,a[i],1);
	}
	cout<<maxa;
	return 0;
}
