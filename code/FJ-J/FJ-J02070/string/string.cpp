#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long cnt=0;
	cin >> n;
	int a[n+5];
	string s[n+5];
	for (int i=0; i<n; i++){
		cin >> a[i];
		cin >> s[i];
	}
	for(int i=0, j=n-1; i<n/2; i++, j--){
		if (s[i]==s[j]){
			if (a[i]>a[j]) a[i+1]+=abs(a[i]-a[j]);
			else a[j-1]+=abs(a[i]-a[j]);
			cnt+=abs(a[i]-a[j]);
		}
		else{
			if(a[i]>a[j]) a[i+1]+=abs(a[i]-a[j]);
			else a[j-1]+=abs(a[i]-a[j]);
			cnt+=(min(a[i], a[j])+abs(a[i]-a[j])*!(i==n/2-1 && n%2==0));
		}
	}
	cout << cnt;
	return 0;
}
