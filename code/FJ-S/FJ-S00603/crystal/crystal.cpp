#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;
const int N = 5e5+10;
int n;
ll  m;
ll a[N];
i128 sum[N];
i128 sm(int i, int j){
	return sum[j]-sum[i-1];
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool k = 1;
	ll p;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i>=3&&a[i]-a[i-1] != a[2]-a[1]) k = 0;
	}
	if(k)p=a[2]-a[1];
	sort(a+1,a+1+n);
//	for(int i = 1;i <= n;i++) cout << a[i] << " ";
//	cout << endl;
	if(k){
		cout << (p==1?(int)sqrt(2*m/p)+1:(int)sqrt(2*m/p)) << endl;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int maxn=-1;
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <=n;j++){
			ll t = a[j];
			int l = j-i+1;
			i128 s = t*l-sm(i,j);
			if((s<m && (m-s)%l==0) || s==m){
				maxn = max(maxn,l);
			}
		}
	}
	cout << maxn << endl;
	return 0;
}

