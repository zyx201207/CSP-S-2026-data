#include <bits/stdc++.h>
using namespace std;
long long n,x;
char b;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> x >> b;
		for(int j = 1;j<=x;j++){
			a+=b;
		}
	}
	long long sz = a.size();
	long long s = sz,ans = 0;
	for(int i = 0;i<=sz/2;i++){
		if(a[i] != a[i+s-1]){
			ans++;
		}
		s-=2;
	}
	cout << ans;
	return 0;
}
