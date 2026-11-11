#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans;
long long a[500010];
long long st[500010];
bool check(long long x){
	for(long long i=x;i<=n;i++){
//			cout<<m<<" "<<a[i]*x-(st[i]-st[i-x])<<"\n";
		if(m>=a[i]*x-(st[i]-st[i-x])){
			
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
//		a[i]+=1e12;
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		st[i]=st[i-1]+a[i];
	}
	long long l=1,r=n;
	while(l<=r){
//		cout<<l<<" "<<r;
		long long mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
//	cout<<check(4998);
	return 0;
} 
