#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500010];
long long d[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	d[0]=0;
	for(int i=1;i<=n;i++){
		d[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++){
		d[i]=d[i]*i+d[i-1];
	}
	d[n]=0;
//	for(int i=1;i<=n;i++){
//		cout<<i+1<<' '<<d[i]<<'\n';
//	}
	if(d[n-1]<=m){
		cout<<n;
		return 0;
	}
	int l=1,r=n;
	while(l<r){
//		cout<<l<<" "<<r<<'\n';
		int mid=(l+r+1)>>1;
		if(d[mid]<=m) l=mid;
		else r=mid-1;
	}
	cout<<l+1;
	return 0;
}
