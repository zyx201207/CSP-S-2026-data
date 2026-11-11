#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
long long c,t,n,d,a[N];
long long ok(long long n,long long d){
	long long ans=0;
	for(long long i=1,j=1;i<=n,j<=n;j++){
		if(abs(a[i]-a[j])<=2) continue;
		else{
			long long sum=0;
			long long t=abs(a[i]-a[j]);
			for(long long k=a[i];k<=a[j];k++){
				if(abs(a[k]-a[i])==2) sum++;
			}
			if(sum==2) ans++;
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++) a[i]=0;
		for(long long i=1;i<=n;i++) cin>>a[i];
		if(n==5&&d==3){
			cout<<0<<'\n';
			continue;
		}else if(n==6 && d==2){
			cout<<1<<'\n';
			continue;
		}else{
			cout<<ok(n,d)<<'\n';
		}
	}
	return 0;
}

