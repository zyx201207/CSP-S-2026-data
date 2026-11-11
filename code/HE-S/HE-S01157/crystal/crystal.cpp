//ÄÜÁ¿Ë®¾§£¨crystal£©
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];//500000
long long b[500005];
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f=1;
		}
	}
	if(f){
		sort(a+1,a+1+n);
	}
	for(int i=1;i<=n;i++){
		b[i]=a[n]-a[i];
	}
	for(int i=1;i<=n;i++){
		long long j=0;
		long long sum=0;
		for(j=i;j>=1&&sum<=m;j--){
			sum+=b[j]-b[i];
		}
		if(m>=sum){
			ans=max(i-j,ans);
		}
	}
	cout<<ans;
	return 0;
}
