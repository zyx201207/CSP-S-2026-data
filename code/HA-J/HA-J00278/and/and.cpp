#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
const int N=2e5+10;
int a[N];
int ans;
void dfs(int i,int hv,int k) {
	if(hv==m) {
		ans=max(ans,k);
		return ;
	}
	for(int j=i+1; j<=(n-m+hv+1); j++) {
		dfs(j,hv+1,k&a[j]);
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n==m) {
		ans= a[1];
		for(int i=2; i<=n; i++) {
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(n<=2e4) {
		if(m==1) {
			ans=0;
			for(int i=1; i<=n; i++) {
				ans=max(ans,a[i]);
			}
			cout<<ans;
			return 0;
		} else if(m==2) {
			ans=0;
			for(int i=1; i<=n; i++) {
				for(int j=i+1; j<=n; j++) {
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans;
			return 0;
		}
	}
	dfs(0,0,pow(2,21)-1);
	cout<<ans;
	return 0;
}
