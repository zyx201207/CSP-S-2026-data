#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+7;
int n,m;
vector<ll> a(N);
vector<bool> v(N);
ll mba(int depth,vector<ll> vec){
	ll mx = 0;
	if(depth == m){
		mx = ~(1ll<<63);
		for (int i = 0;i < m;i++)
		{
			mx&=vec[i];
		}
		return mx;
	}
	for (int i = 0;i < n;i++)
	{
		if(!v[i]){
			v[i] = 1;
			vec[depth] = a[i];
			mx = max(mx,mba(depth+1,vec));
			v[i] = 0;
		}
	}
	return mx;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		v[i] = 0;
	}
	cout << mba(0,*(new vector<ll>(m)));
	return 0;
}
