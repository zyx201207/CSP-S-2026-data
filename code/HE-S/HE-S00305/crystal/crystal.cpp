#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n,m,a[N],ans,s[N],l,r,sum[N];
bool check(ll x){
	//cout << x << endl;
	memset(s,0,sizeof(s));
	for(int i=1;i<=n-x+1;i++){
		for(int j=i;j<=i+x-1;j++){
			s[i] += a[i+x-1] - a[j];
		}
	}
//	for(int i=1;i<=n-x+1;i++){
//		s[i] += a[i+x-1]*x - (sum[i+x-1]-sum[i-1]);
//	}
//	for(int i=1;i<=n-x+1;i++){
//		cout << s[i] << " ";
//	}
	for(int i=1;i<=n-x+1;i++){
		if( s[i] <= m )  return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	sort(a+1,a+1+n);
	l= 0,r = n;
	while( l <= r ){
		ll mid = (l+r) >> 1;
		if( check(mid) ){
			//cout << mid << endl; 
			l = mid+1;
			ans = max(ans,mid);
		}
		else{
			r = mid-1;
		}
	}
	cout << ans << endl;
	return 0;
} 
