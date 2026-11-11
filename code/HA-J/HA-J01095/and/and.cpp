#include<bits/stdc++.h>
using namespace std;
int n,m,zc,a[200001],maxs=-1;
int h,cnt1,cnt2;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(maxs<a[i]) {
			maxs=a[i];
		}

	}if(maxs<=4){	sort(a,a+m);
		cout<<a[n];

	}
	if(n==1) {
		cout<<maxs;
		return 0;
	}
	sort(a,a+m);for(int i=n;i>=1;i--){
		
}
maxs=0;
	for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
		maxs=max(maxs,a[i]&a[j]);
	}
	}cout<<maxs;
	
	return 0;
}

