#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool ok(int k){
	for(int j=0;j<=n-k;j++){
		long long ans=0;
		for(int i=j+1;i<j+k;i++){
			ans+=(i-j)*(a[i+1]-a[i]);
		}
		if(ans<=m) return true;
	}
	return false;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(ok(mid)==true){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<l;
	return 0;
}