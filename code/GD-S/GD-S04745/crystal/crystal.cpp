#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500001],sum[500001];
bool check(int x){
	long long num=LLONG_MAX;
	for(int i=1;i+x-1<=n;i++){
		int j=i+x-1;
		num=min(num,(a[j]*(j-i+1)-(sum[j]-sum[i-1])));
	}
	return num<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n,ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
/*
²âÊÔÑùÀý 
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
