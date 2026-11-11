#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int N = 5e5 + 10;

vector<ll> a;
ll n;
ll m;
ll pre = 0;
ll add = 0;
ll usek = 0;
ll ans = -1;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\crystal4.in", "r", stdin);
	//freopen("C:\\Users\\Administrator\\Desktop\\test.out", "w", stdout);
	cin >> n >> m;
	
	a.resize(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	

	for(int i = 1; i <= n; i++) {
		add = (a[i] - a[i - 1]) * usek;
		pre += add;
		if(pre <= m) {
			usek++;
			ans = max(ans, usek);
		}
		else {
			while(pre > m) {
				pre = pre - (a[i] - a[i - usek]);
				usek--;
			}
			usek++;
		}
	}	

	
	cout << ans;
	return 0;
}
/*for(auto A:a)
cout<<A<<endl;*/
//cout<<"now:"<<i<<" maintain:"<<usek<<" all:"<<pre<<endl;
//cout<<"now:"<<i<<" delet:"<<i - usek<<" maintain:"<<usek<<" all:"<<pre<<endl;

