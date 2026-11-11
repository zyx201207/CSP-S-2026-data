#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
long long n,m;
long long a[N];
bool cmp(long long a,long long b){
	return a > b;
}

int main(){
	freopen("and.in",r,stdin);
	freopen("and.out",w,stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long ans = (long long)a[1] & a[2];
	long long i=3;
	while(i<=m){
		ans = (long long)ans&a[i];
		i++;
	}
	cout << ans;
	
	return 0;
}
