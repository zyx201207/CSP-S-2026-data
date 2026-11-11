#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[100001],h =0;
	string s;
	string p;
	cin >> n;
	for (int i = 0;i<n;i++){
		cin >> a[i] >> s[i];
		for (int j = h;j<a[i]+h;j++){
			p[j] = s[i];
		}
		h+=a[i];
	}
	int map = 0;
	for (int i = 0;i<p.size();i++){
		for (int j = p.size()-1;j>=0;j--){
			if (p[i] != p[j]){
				map++;
			}
		}
	}
	int sum = map/2;
	cout << sum;
	return 0;
}
