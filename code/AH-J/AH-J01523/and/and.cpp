#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],s,maxn=-1,f[25][25][20005];
long long dfs(long long u,long long x,long long s){
	if(u>m)maxn=max(maxn,s);
	for(long long i=x+1;i<=n;i++){
		if(f[u+1][i][s&a[i]]!=0)return f[u+1][i][s&a[i]];
		else f[u+1][i][s&a[i]]=dfs(u+1,i,s&a[i]);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		for(long long i=1;i<=n;i++){
			dfs(2,i,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	else{
		sort(a+1,a+1+n);
		s=a[n];
		for(long long i=n-1;i>=n-m+1;i--)s&=a[i];
		cout<<s;
	}
	return 0;
}
