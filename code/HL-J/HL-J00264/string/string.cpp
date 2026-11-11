#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll cnt;
	char a;
};
vector <char> num;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll ans = 0;
	ll n;
	cin >> n;
	node c[n];
	for(int i = 0;i < n;i++){
		cin >> c[i].cnt;
		cin >> c[i].a;
		for(int z = 0;z < c[i].cnt;z++){
			num.push_back(c[i].a);
		}
	}
	if(n % 2 == 1){
		for(int i = 1;i < n;i++){
			ll cnt2 = n / 2;
			if(num[cnt2 - i] == num[cnt2 + i]){
				continue;
			}else{
				ans++;
			}
		}
	}else{
		for(int i = 0;i < n;i++){
			ll cnt2 = n / 2,cnt3 = ceil(1.0 * n / 2);
			if(num[cnt2 - i] == num[cnt3 + i]){
				continue;
			}else{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
