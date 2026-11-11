#include<bits/stdc++.h>

using namespace std;

int n,ans;
long long m,a[500005];
long long f[500005];

int main(){
	freopen("crystal.in","r",stdin);	
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		++ans;
		f[i]=f[i-1]+(a[i]-a[i-1])*(i-1);
		if(f[i]>m){
			break;
		}
	}
	int sum=0;
	for(int i=n-1;i;--i){
		++sum;
		f[i]=f[i+1]+(a[i+1]-a[i])*(n-i);
		if(f[i]>m){
			ans=max(ans,sum);
			break;
		}
	}
	cout<<ans;
	return 0;
}
