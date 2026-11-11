#include<bits/stdc++.h>
using namespace std;
int n, m;
int ans=-pow(2,30);
int b[200010];
int a[200010];
void dfs(int p,int x,int q,int t) {
	if(p==q+1) {
		int num=b[1];
		for(int i=2; i<=q; i++) {
			num=num&b[i];
//			cout<<b[i]<<" ";
		}
//		cout<<num<<"\n";
		ans=max(ans,num);
		return ;
	}
	for(int i=t; i<=n; i++) {
		b[x]=a[i];
		dfs(p+1,x+1,q,i+1);
	}
	return ;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	dfs(1,1,m,1);
	cout<<ans;
	return 0;
}
