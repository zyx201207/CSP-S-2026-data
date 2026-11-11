#include <bits/stdc++.h>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infLL 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef pair<int,int> pii;

const int maxn = 5e5+5;
ll a[maxn], s[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int n; ll m;
	cin>>n>>m;
	a[0] = -infLL;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	s[0] = 0;
	for(int i=1;i<=n;i++){
		s[i] = s[i-1] + a[i];
	}
//	//debug
//	cout<<"s:\n";
//	for(int i=1;i<=n;i++) cout<<s[i]<<' ';
//	cout<<'\n';
	
	int l = 1, r = 1, ans = 0;
	i128 req = 0;
	while(r <= n){
		while(r <= n-1 && a[r] == a[r+1]) r++;
//		cout<<"r go to "<<r<<'\n';
		req = (i128)a[r] * (r-l+1) - s[r] + s[l-1];
		while(req > m){
//			cout<<"with l="<<l<<", req="<<(ll)req<<", so we l++\n";
			req -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r-l+1);
//		//debug
//		cout<<"now l="<<l<<", r="<<r<<", req="<<(ll)req<<'\n';
		
		r++;
	}
	cout<<ans<<'\n';
	
	return 0;
}
