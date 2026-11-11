#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll a[500005],c[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll m;
	int n;
	cin >> n >> m;
	bool t = 1;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		if (a[i] != i) t = 0; 
	}
	if(t){
		int x = int(sqrt(m));
		int ans = min(x,n - 1);
		for(int i = x;i*i+i<= m * 2 and i < n;i++){
			ans = i;
		}
		cout << ans + 1;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++){
		c[i] = a[i] - a[i-1];
	}
	int ans = 1,cnt = 1;
	ll sum = 0,temp = 0;
	for(int i = n;i>=ans;i--){
		if(i!=n and a[i] == a[i+1]) continue;
		sum = 0,cnt = 1,temp = 0;
		for(int k = i;k>1;k--){
			temp += c[k];
			sum += temp;
			if(sum>m){
				break;
			}
			cnt++;
		}
		ans = max(ans,cnt);
	}
	cout << ans;
	return 0;
}
