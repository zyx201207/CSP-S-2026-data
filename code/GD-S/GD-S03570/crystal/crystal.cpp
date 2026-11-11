#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 500010 
unsigned long long m;
ll n,l,r;
ll a[maxn];
//rp++
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	l = 1;
	ll ans = 0;
	ll sum = 0;
	for(r = 1;r <= n;r++){
		sum += (r-l)*(a[r]-a[r-1]);
		while(l < r && sum > m){
			sum -=a[r]-a[l];
			l++;
		}
		ans = max(r-l+1,ans);
	}
	cout << ans;
	return 0;
}
