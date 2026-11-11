#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005];
bool check(long long x,long long k){
	if(a[k]*x-(s[k]-s[k-x])<=m)return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long maxn=-1;
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(long long i=2;i<=n;i++){
		long long l=1,r=i,ans=0;
		while(l<=r){
			long long mid=(l+r)/2;
			if(check(mid,i))l=mid+1,ans=mid;
			else r=mid-1;
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn<<"\n";
	return 0;
}
