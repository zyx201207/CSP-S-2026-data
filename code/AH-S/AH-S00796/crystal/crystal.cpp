#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ans;
bool f=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=3)f=0;
	}
	if(f){
		for(long long i=1;i<=n;i++){
			long long l=1,r=i,t=a[i]-a[i-1];
			while(l<r){
				long long mid=(l+r)/2;
				if(((t+t*(i-mid))*(i-mid))/2<=m)r=mid;
				else l=mid+1;
			}
			ans=max(ans,i-l+1);
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		long long l=1,r=i;
		while(l<r){
			long long mid=(l+r)/2;
			if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
