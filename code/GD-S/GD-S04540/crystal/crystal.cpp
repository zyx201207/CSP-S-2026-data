#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+7;
int n,ans;
ll m;
ll a[N];
ll d[N];
bool isa = 1;

void chk(){
	for(int i = 2;i <= n;i++){
		int cnt = 1;
		ll num = 0;
		for(int j = i;j <= n && num <= m;j++){
			num += d[j]*(j-i+1);
			if(num > m) break;
			cnt++;
		}
		ans = max(ans,cnt);
	}
}

void chka(){
	int cnt = 1;
	ll num = 0;
	for(int i = 1;i <= n;i++){
		num += i;
		if(num <= m)
			cnt++;
	}
	ans = max(ans,cnt);
	cout << ans << endl;
}

bool chkb(){
	for(int i = 3;i <= n;i++){
		if(d[i] != d[i-1]) return 0;
	}
	int cnt = 1;
	ll num = 0;
	for(int i = 2;i <= n;i++){
		num += d[i]*(i-1);
		if(num <= m)
			cnt++;
	}
	ans = max(ans,cnt);
	return 1;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != i) isa = 0;
	}
	sort(a+1,a+1+n);
	for(int i = 2;i <= n;i++)
		d[i] = a[i]-a[i-1];
	if(isa){
		chka();
		return 0;
	}
	if(chkb()){
		cout << ans << endl;
		return 0;
	}
	chk();
	cout << ans << endl;
	return 0;
}
