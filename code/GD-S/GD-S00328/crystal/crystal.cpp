#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long n,m,s,e,a[5*N],ans;
long long f(int k){
	long long t[N],num=0,ans=0;
	for(int i=1;i<=n;i++){
		t[i]=abs(a[i]-k);
	}
	sort(t+1,t+n+1);
	for(int i=1;i<=n;i++){
		if(num+t[i]<=m){
			num+=t[i];
			ans++;
		}
	}
	return ans;
}
int main(){  
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	long long kk=pow(10,8);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s=min(s,a[i]);
		e=max(e,a[i]);
	}
	if(m>kk){
		long long mid=(a[1]+a[n])/2;
		cout<<f(kk);
		return 0;
	}
	for(int i=s;i<=e;i++){
		ans=max(f(i),ans);
	}
	printf("%lld",ans);
	return 0;
}
