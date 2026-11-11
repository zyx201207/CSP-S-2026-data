#include<bits/stdc++.h>
using namespace std;
long long n,MXN=0;
long long m;
long long a[500005];
long long b[500005];
long long f[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		f[i]=1;
	}
	sort(a+1,a+n+1);
	if(n>5000){
		long long d=a[2]-a[1];
		m/=2;
		int i=1;
		for(;i<=n;i++){
			m-=i;
			if(m<0){
				break;
			}
		}
		cout<<i-1;
		return 0;
	}
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		b[i]+=b[i-1];
	}
	for(int i=2;i<=n;i++){
		long long ans=0;
		for(int j=i-1;j>=1;j--){
			ans+=b[i-1]-b[j-1];
			if(ans<=m){
				f[i]++;
			}
			else{
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		MXN=max(MXN,f[i]);
	}
	cout<<MXN;
	return 0;
}
