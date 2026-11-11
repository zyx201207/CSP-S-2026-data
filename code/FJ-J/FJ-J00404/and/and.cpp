#include<bits/stdc++.h>
using namespace std;

long long n,m,ans=0,t;

bool cmp(long long a,long long b) {
	return a>b;
}

void fs(long long i,const vector<long long> a,long long sum=LLONG_MAX,long long tm=m) {
	if(tm==1) {
		for(;i<n;i++) {
			if((sum&(a[i]))>ans) ans=sum&(a[i]);
		}
		return;
	}
	for(long long im=n-tm;i<=im;i++) {
		t=sum&(a[i]);
		if(t<ans) continue;
		fs(i+1,a,t,tm-1);
	}
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	vector<long long> a(n);
	for(long long& i:a) cin >> i;
	sort(a.begin(),a.end(),cmp);
	fs(0,a);
	cout << ans;
	return 0;
} 
