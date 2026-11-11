#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int C(long long x){
	vector<long long> f;
	f.push_back(0);
	for(int i=1;i<=x;i++){
		f.push_back(abs(a[x]-a[i]));
		f[i]+=f[i-1];
		if(f[i]>m) return false;
	}
	if(f[x]>m) return false;
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(C(mid)) l=mid+1;
		else r=mid-1;
	}
	if(C(l)) cout << l;
	else cout << r;
	return 0;
}
