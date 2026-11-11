#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],sum[500100];
bool check(int x){
	long long cnt=2e18;
	for(int i=x;i<=n;i++){
		cnt=min(cnt,a[i]*x-sum[i]+sum[i-x]);
	}
	return cnt<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long l=1,r=n;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	cout<<l;
	return 0;
}
