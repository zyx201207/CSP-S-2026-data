#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
long long a[N];
long long n,k;
bool check(long long mid){
	long long res=0;
	for(long long i=1;i<=n;i++){
		if(a[i]>mid) break;
		res+=mid-a[i];
	}
	return res<=k;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long l=a[1],r=a[n];
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		if(a[i]<=r) ans++;
	}
	cout<<ans;
	return 0;
}
