#include <bits/stdc++.h>
using namespace std;
long long n;
long long ans = 0;
string now;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		long long a;
		char b;
		cin >> a >> b;
		for(int j = 0; j < a; j++){
			now += b;
		}
	}
	long long lo = now.size();
	for(int i = 0; i < now.size() / 2; i++){
		if(now[i] != now[now.size() - i - 1]){
			ans++;
		}
	}
	cout << ans;

	return 0;
}

