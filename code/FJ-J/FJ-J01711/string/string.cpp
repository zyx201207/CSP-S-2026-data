#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long a[n+1];
	char c[n+1];
	int z=1;
	char s[1000000000000001];
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		for(int j=1;j<=a[i];j++) {
			s[z]=c[i];z++;
		}
	}
	long long cnt=0;
	for(int i=1;i<=z/2;i++){
		if(s[i]!=s[z-i+1]) cnt++;
	}
	cout << cnt;
	return 0;
}
