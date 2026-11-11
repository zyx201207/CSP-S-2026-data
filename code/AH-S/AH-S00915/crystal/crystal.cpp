#include<bits/stdc++.h>
using namespace std;
long long a[5000001],d[5000001],f[5000001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(int i=n-2;i>=0;i--){
		d[i]=d[i+1]+a[i+1]-a[i];
	}
	for(int i=n-2;i>=0;i--){
		f[i]=f[i+1]+d[i];
	}
	long long mx=0,mm=0;
	for(long long l=0,r=1;r<n;r++){
		while(f[l]-f[r]-d[r]*(r-l)>m)l++;
		mx=max(mx,r-l+1ll);
	}
	cout<<mx;
	return 0;
}
