#include<bits/stdc++.h>
using namespace std;
long long n,m,e[1000000+5],maxn;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>e[i];
	sort(e+1,e+n+1,greater<long long>());
	for(int i=1;i<=n-m+1;i++){
		long long maxnn=e[i];
		if(maxn>=e[i]){
			cout<<maxn;
			return 0;
		}
		for(int j=i+1;j<=m;j++)
			maxnn&=e[j];
		maxn=max(maxn,maxnn);
	}
	cout<<maxn;
	return 0;
}
