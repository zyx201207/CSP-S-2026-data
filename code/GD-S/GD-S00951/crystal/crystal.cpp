#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n;
long long m, a[N], s[N];

//(a[r]-a[l])*(r-l+1)-s[r]+s[l-1];
long long check(long long x){
	long long l=1, r=x, tmp;
	while(l<r){
		long long mid = (l+r) >> 1;
		tmp = (a[x]-a[mid])*(x-mid+1)-s[x]+s[mid-1]+a[mid]*(x-mid+1);
		if(tmp>m) l = mid+1;
		else r = mid;
	}
	tmp = (a[x]-a[r])*(x-r+1)-s[x]+s[r-1]+a[r]*(x-r+1);
	if(tmp<=m) return x-r+1;
	else return -1;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i=1;i<=n;++i){
		s[i] = s[i-1]+a[i];
	}
	long long ans=-1;
	for(int i=1;i<=n;i++){
		long long ch = check(i);
		if(ch==-1) break;
		ans = max(ch, ans);
	}
	cout << ans << endl;
	return 0;
} 
