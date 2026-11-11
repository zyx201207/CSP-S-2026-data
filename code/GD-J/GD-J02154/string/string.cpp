#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 5;
ll n;
ll a[N];
string s[N];
ll ans,cnt,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(ll i = 1;i <= n;i++){
		cin >> a[i] >> s[i];
		sum += a[i];
	}
	for(ll i = 1;i <= n;i++){
		if(s[i] != s[n - i + 1]){
			cnt += a[i];
		}
	}
	if(sum % 2 == 0){
		cout << cnt / 2;
	}else{
		cout << (cnt - 1) / 2;
	}
	return 0;
} 


