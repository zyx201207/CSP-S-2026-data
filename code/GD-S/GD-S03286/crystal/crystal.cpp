#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans;
long long b[500001];
bool ok(long long k){
	for(int i=k;i<=n;i++){
		if(1LL*a[i]*k-(b[i]-b[i-k])<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	long long le=1,ri=n,mid=0;
	while(le<ri){
		mid=(le+ri+1)>>1;
		if(ok(mid)){
			ans=mid;
			le=mid;
		}
		else{
			ri=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
