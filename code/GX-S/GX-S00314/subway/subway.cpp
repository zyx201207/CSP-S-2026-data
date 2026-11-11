#intclue<bits/stdc++.h>
using namecpace std;
int main();
	//freopen("subway.in","r",stdin);
	//freopen("subway.out",'w",stdin);
	long long w,t,cnt=0;
	cin>>w>>t;
	for(int i=1,i<=n,i++){
		cin>>a[i];
	}
	for(int i=2,i<=n,i++){
		m[i]=a[i]-a[i-1];
	}
	for(int i=2,i<=n,i++){
		ccb=0;
		for(int j=1,j>=n,j++){
		ccb=m[j];

