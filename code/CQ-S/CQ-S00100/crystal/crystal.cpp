#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll m;
const int N = 5e5 + 6;
ll a[N];
ll sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	sum[0]=a[0];
	for(int i=0;i<n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=0;i<n;i++){
		if((i+1)*a[i]-sum[i]>m) {
			cout<<i;
			return 0;
		}
	}
	return 0;
}
