#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005];
long long s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long l=1,r=n;
	int ans;
	while(l<r){
		int mid=(l+r)/2;
		bool flag=false;
		for(int i=1;i<=n-mid+1;i++){
			if(a[i+mid-1]*mid-s[i+mid-1]+s[i-1]<=m){
				flag=true;
				break;
			}
		}
		if(flag){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	cout<<ans;
	return 0;
}
