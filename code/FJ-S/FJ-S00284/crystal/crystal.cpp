#include<bits/stdc++.h>
using namespace std;

const int N=5e5+7;

int n;
long long m;
long long a[N];
long long s[N];

bool check(int k, int mid){
	long long sq = s[k-1]-s[mid-1];
	return a[k]*(k-mid)-sq > m;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	freopen("crystal4.in", "r", stdin);
//	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%lld", a+i);
	}
	sort(a+1, a+n+1);
	s[0] = 0;
	for(int i=1;i<=n;i++){
		s[i] = s[i-1]+a[i];
	}
	int res = 0;
	for(int i=1;i<=n;i++){
		int l=1, r=i+1;
		int mid = (l+r)/2;
		while(l<r){
			if(check(i, mid)){
				l = mid+1;
			}else{
				r = mid;
			}
			mid = (l+r)/2;
//			cout << i << ' ' << l << ' ' << r << ' ' << mid << endl;
		}
		res = max(i-l+1, res);
//		cout << res << endl;
	}
	cout << res;
	return 0;
}
