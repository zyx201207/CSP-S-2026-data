#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=a[i]+b[i-1];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	for(long long l=1,r=1,sum=0;r<=n;){
		while(l<r&&a[r]*(r-l+1)-(b[r]-b[l-1])>m){
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
		sum+=(a[r]-a[r-1])*(r-l);
	}
	cout<<ans;
	return 0;
}
