#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5;
int n;
ll m,a[N];
ll d[N],s[N];

bool check(int mid){
	//cout << mid << ": ";
	// 连续一段最优
	// 连续 mid 个能量值相同 
	// 从 i 开始 
	ll ns=0;
	// l=1，直接算 
	for(int i=2;i<=mid;i++){
		ns+=(i-1)*d[i];
	}
	//cout << ns << " ";
	if(ns<=m){
		//cout << "true\n";
		return true;
	}
	for(int l=2;l+mid-1<=n;l++){
		int r=l+mid-1;
		ll x=s[r-1]-s[l-1];
		ll y=d[r]*(r-l);
		ns+=y-x;
		//cout << ns << " ";
		if(ns<=m){
			//cout << "true\n";
			return true;
		}
	}
	//cout << "false\n";
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		s[i]=s[i-1]+d[i];
	}
	
	int l=1,r=n;
	int res=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			res=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	
	cout << res << "\n";
	return 0;
}
