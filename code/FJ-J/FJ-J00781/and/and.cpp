#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],ans;
bool u[200005];
void dfs(int k){
	if(k>m){
		long long s=b[1];
		for(int i=2;i<=m;i++)
			s=s&b[i];
		ans=max(ans,s);
		return ;
	}
	for(int i=k;i<=n;i++){
		if(!u[i]){
			b[k]=a[i];
			u[i]=1;
			dfs(k+1);
			u[i]=0;
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
