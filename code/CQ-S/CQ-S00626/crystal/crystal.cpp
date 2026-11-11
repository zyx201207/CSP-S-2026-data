#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,m;
long long a[N];
bool check(long long x){
	long long sum=0;
	for(long long i=1;i<x;i++) sum+=(a[x]-a[i]);
	return sum<=m;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<l-1;
	return 0;
}
