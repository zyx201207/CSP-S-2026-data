#include<bits/stdc++.h>
using namespace std;

int n, ans, q;
long long m;
long long arr[500005], sum[500005];

bool cmp(long long a, long long b){
	return a>b;
}

int find(int x){
	int l=x+1, r=n, mid;
	long long tmp;
	while(l<r){
		mid = (l+r) >> 1;
		tmp = (arr[x]*(mid-x))-(sum[mid]-sum[x]);
		if(tmp < m){
			l = mid+1;
		}else if(tmp > m){
			r = mid;
		}else{
			l = r;
		}
	}
	return l-x;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	sort(arr+1, arr+1+n, cmp);
	for(int i=1;i<=n;i++){
		sum[i] = sum[i-1]+arr[i];
	}
	for(int i=1;i<=n;i++){
		ans = max(ans, find(i));
	}
	cout << ans << endl;
	return 0;
}
