#include<bits/stdc++.h>
using namespace std;
void fo(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	return;
}
void sol(){
	long long n,a[500001],s[500001]={},m,l=1,r;
	cin>>n>>m,r=n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	while(l<r){
		long long mid=(l+r+1)/2;
		bool f=0;
		for(int i=mid,j=0;i<=n;i++,j++){
			long long t=i*a[i]-s[i];
			if(t-(j*a[i]-s[j])<=m)f=1;
		}
		//cout<<l<<' '<<r<<'\n';
		if(f)l=mid;
		else r=mid-1;
	}
	cout<<l;
	return;
}
int main(){
	fo();
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		sol();
	}
	return 0;
}
