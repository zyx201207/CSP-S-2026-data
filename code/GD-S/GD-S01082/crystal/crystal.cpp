#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
const int N = 500010;
int n,m;
ll a[N],s[N],p[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++){
		s[i] = a[i]-a[i-1];
	}
	for(int i = 1;i <= n;i++){
		p[i] = p[i-1]+s[i];
	}
	ll i = 1,j = 1;
	ll ans = 1,nw = 0,h = 0;
	j++;nw+=(j-i)*s[j];
	while(i<=n&&j<=n){
		if(nw<=m){
			ans = max(ans,j-i+1);
			j++;nw+=(j-i)*s[j];
		}
		else{
			i++;nw-=p[j]-p[i-1];
		}
	}
	ans = max(ans,j-i+1);
	cout << ans;
	return 0;
}
