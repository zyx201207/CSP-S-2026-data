#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","w",stdin);
	freopen("crystal.out","r",stdout);
	long long m,n,cha=pow(10,18),ans=0;
	cin>>n>>m;
	vector<long long> a(n);
	vector<long long> c(n),d(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	c[0]=a[0];
	d[0]=a[0];
	for(int i=1;i<=n-1;i++){
		c[i]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=i;j++){
			d[i]+=c[j]*j;
		}
		if(d[i]-m<cha&&d[i]-m>0){
			cha=d[i]-m;
			ans=i;
		}
	}
	cout<<ans;
	return 0;
}
