#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],dp[N];
long long n,m;
bool cmp(long long a,long long b){
	return a<b;
}
bool check(long long num){
	long long x=m;
	for(long long i=1;i<=num;i++){
		x-=dp[i]*(i);
		if(x<0)return false;
	}
	return true;
}
int main(){
	
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(long long i=1;i<=n;i++){
		dp[i]=a[i]-a[i-1];
//		cout<<a[i]<<' ';
	}
	
	long long l=0,r=1e9,mid=(l+r+1)/2;
	while(l<r){
		if(check(mid)){
			l=mid+1;
		}
		else r=mid;
		mid=(l+r)/2;
//		cout<<r<<' '<<l<<' '<<mid<<' '<<check(mid)<<endl;
	}
	cout<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
