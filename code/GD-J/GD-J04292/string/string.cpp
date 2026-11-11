#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l = 0,a[200005];
	long long cnt = 0;
	char c[200005];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
	}
	while(l <= n){
		if(c[l] != c[n-l-1]){
			cnt += min(a[l] , a[n-l-1]);
		}
		if(a[l] > a[n-l-1]){
			a[l] -= a[n-l-1];
			n--;
		}
		else{
			a[n-l-1] -= a[l];
			l++;
		}
	}
	cout << cnt;
	return 0;
}
