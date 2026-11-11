#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500024];
long long f(long long z,long long b[],long long num){
	long long i=z-1,sum=1;
	while(num>0&&i>0){
		if(b[z]>=b[i]){
			if(num>=b[z]-b[i]){
				num-=(b[z]-b[i]);
				sum++;
			}else{
				break;
			}
		}
		i--;
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=n,tem,mid,ans=0;
	while(l<r){
		mid=(l+r)/2;
		tem=f(mid,a,m);
		if(tem>ans){
			ans=tem;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout << ans;
	return 0;
}
