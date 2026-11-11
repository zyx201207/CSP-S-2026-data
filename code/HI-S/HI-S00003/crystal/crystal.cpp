#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
long long a[500001];
bool check(long long mid){
	long long ans=m,count;
	for(int i=n ; i>=1 ; i--){
		count=1;
		ans=m;
		for(int j=i-1 ; j>=1 ; j--){
			if(ans-(a[i]-a[j])<0){
				break;
			}
			ans-=(a[i]-a[j]);
			count++;
		}
		if(count>=mid) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m ;
	for(int i=1 ; i<=n ; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			sum=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout << sum;
	return 0;
} 
