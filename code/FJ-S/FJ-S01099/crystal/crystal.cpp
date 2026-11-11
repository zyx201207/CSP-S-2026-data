#include<bits/stdc++.h>
std::string acdegf="crystal",acdegftmp;

using namespace std;
long long n,m,a[500005],ans,tx;

long long main() {
	acdegftmp=acdegf+".in";
	freopen(acdegftmp.c_str(),"r",stdin);
	acdegftmp=acdegf+".out";
	freopen(acdegftmp.c_str(),"w",stdout);
	cin>>n>>m;
	
	for(long long i=1; i<=n; ++i)scanf("%lld",a+i),a[i]+=1e12;
	sort(a+1,a+1+n);
	for(long long i=0,j=1; i<=j&&j<n; ++i) {
//		cout<<i<<' '<<j<<'\n';
//		cout<<a[j+1]<<' '<<a[(i+j+1)>>1]<<'\n';
		while(tx<=m&&j<n) {
			tx+=(a[j+1]-a[j])*(j-i);
			++j;
//			cout<<i<<' '<<j<<' '<<a[j]<<' '<<a[(i+j+1)>>1]<<' '<<(i+j+1>>1)<<' '<<tx<<'\n';
		}
		if(tx>m||j>n){
			--j;
			tx-=(a[j+1]-a[j])*(j-i);
		}
		ans=max(j-i,ans);
		
		tx-=a[j]-a[i+1];
	}
	cout<<ans;
}
