#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
int check(int gs){
	int xy=0;
	for (int i=1;i<gs;i++) xy+=a[gs]-a[i];
	if (xy<=m) return 1;
	for (int i=2;i<=n-gs+1;i++){
		xy=xy+(gs-1)*(a[i+gs-1]-a[i+gs-2])-(a[i+gs-2]-a[i-1]);
		if (xy<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n+1;
	while (l<=r-2){
		int mid=(l+r)/2;
		if (check(mid))l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}
