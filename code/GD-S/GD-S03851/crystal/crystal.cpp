#include<bits/stdc++.h>
using namespace std;
long long a[500001],b[500001],m;
int n;
bool ck(int x){
	for(int i=x;i<=n;i++){
		long long s=b[i]-b[i-x];
		if(x*a[i]-s<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int l=1,r=n+1;
	while(r-l>1){
		int mid=(r+l)>>1;
		if(ck(mid))l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}
