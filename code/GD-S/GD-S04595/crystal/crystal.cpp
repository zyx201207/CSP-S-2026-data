#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int n;
long long m,x;
long long a[N],b[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l =1,r = n;
	for(int i = 1;i<=n;i++){
		sum[i] = sum[i-1] + a[i];
	}
	while(l <= r){
		bool f = 0;
		int mid = (l + r) / 2;
		for(int i = mid;i<=n;i++){
			x = mid * a[i] - (sum[i] - sum[i - mid]);
			if(x <= m){
				l = mid + 1;
				f = 1;
			}
		}
		if(!f) r = mid - 1;
	}
	cout<<r;
	return 0;
}
