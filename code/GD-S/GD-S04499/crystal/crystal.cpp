#include<bits/stdc++.h>
template<class T>inline bool chkmx(T&x, const T&v) {return x<v?x=v,1:0; }
template<class T>inline bool chkmn(T&x, const T&v) {return x>v?x=v,1:0; }
#define F(i,j,k) for(auto i=(j); i<=(k); i++)
#define G(i,j,k) for(auto i=(j); i>=(k); i--)
#define pb push_back
using ll = long long;
using namespace std;

const int N = 5e5+5;

int n;
ll m, a[N];

void mian(int Ca) {
	cin>>n>>m;
	F(i,1,n) cin>>a[i];
	sort(a+1, a+n+1);
	int as=1;
	ll sm=0;
	for(int l=1, r=2; r<=n; r++) {
		sm+=(a[r] - a[r-1])*(r-l);
		while(l<=r && sm>m) sm -= a[r] - a[l], l++;
		if(l<=r) chkmx(as, r-l+1);
	}
	cout<<as;
}
/*
*/
int main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int Ca=0, Ti=1;
	F(_,1,Ti) mian(Ca);
	return 0;
}

