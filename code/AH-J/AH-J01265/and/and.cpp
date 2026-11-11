#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long a[N]; 
int n,m;
long long maxn;
void dfs(int idx,int k,long long sum){
	if(k==m){
		maxn=max(maxn,sum);
		return ;
	}
	if(idx==n+1){
		return ;
	}
	if(k==0){
		dfs(idx+1,1,a[idx]);
	}else{
		dfs(idx+1,k+1,sum&a[idx]);
	}
	dfs(idx+1,k,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long mn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mn=max(mn,a[i]);
	}
	if(n<=25){
		dfs(1,0,0);
		cout<<maxn;
	}else if(m==1){
		cout<<mn;
	}else if(m==2){
		long long g=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				g=max(g,a[i]&a[j]);
			}
		}
		cout<<g;
	}else{
		sort(a+1,a+n+1);
		long long o=a[n];
		for(int i=n-1;i<=n-m+1;i++){
			o&=a[i];
		}
		cout<<o;
	}
	return 0;
}
