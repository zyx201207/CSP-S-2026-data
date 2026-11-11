#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	int gg[200005],ll = 0;
	char hh[200005];
	for(int i = 1; i <= n; i++){
		cin >> gg[i] >> hh[i];
		ll+=gg[i];
	}
	int ans = hh[1],kk = 0;
	for(int i = 2; i <= n; i++){
		if(hh[i] == ans){
			kk++;
		}
	}
	if(ll - kk == 1){
		cout << 0;
		return 0;
	}
	string s;
	long long f = 1;
	long long j = 1;
	while(f <= n){
		if(gg[f] > 0){
			s[j] = hh[f];
			j++;
			gg[f]--;
		}
		if(gg[f] == 0){
			f++;
		}
	}
	long long l = 1,r = ll,cnt = 0;
	while(l <= r){
		if(s[l] != s[r]){
			l++;
			r--;
			cnt++;
		}
		else{
			l++;
			r--;
		}
	}
	cout << cnt;
	return 0;
}
