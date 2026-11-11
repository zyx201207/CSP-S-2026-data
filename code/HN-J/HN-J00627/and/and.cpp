#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxm1=INT_MIN;
bool v[200005];
void dfs(long long x,long long maxm2){
	if(x==m+1){
		maxm1=max(maxm1,maxm2);
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			if(maxm2==0){
				dfs(x+1,a[i]);
			}else dfs(x+1,maxm2&a[i]);
			v[i]=0;
		} 
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<maxm1;
	return 0;
}
