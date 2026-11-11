#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N],b[N],n,m;
bool check(long long x){
	long long sn=1;
	for (long long i=x;i<=n;i++){
		if (m>=a[i]*x-(b[i]-b[i-x])){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for (long long i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	long long left=1,right=n;
	while (left+1<right){
		long long mid=(left+right)>>1;
		if (check(mid)){
			left=mid;
		}else{
			right=mid-1;
		}
	}
	cout << left;
	return 0;
}
