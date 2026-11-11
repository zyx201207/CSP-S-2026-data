#include <bits/stdc++.h>

using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long  a[25];string b[25];
	cin  >> n;
	
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];	
	}
	 long long cnt;
	for(int i=0;i<n/2;i++){
		if(a[i]!=a[n-i-1]){if(b[i]!=b[n-1-i]) cnt +=abs(a[i]-a[n-1-i]);
	}
}
	cout << cnt;
	return 0;
}
