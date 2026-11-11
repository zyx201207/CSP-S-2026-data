#include<bits/stdc++.h>
using namespace std;
long long ans;
int n;
int a[200050];
char c[200050];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	long long sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	long long half = sum / 2;
	if(sum & 1)	   half++;
	int li=1, ri=n;
	long long l=0, r=0;
	long long llef=a[li], rlef=a[ri];
	while(l < half){
		long long mn;
		if(llef >= rlef){
			mn = rlef;
		}
		else{
			mn = llef;
		}
		l += mn;
		llef -= mn;
		rlef -= mn;
		if(c[li] != c[ri]){
			ans += mn;
		}
		if(llef == 0){
			llef = a[++li];
		}
		if(rlef == 0){
			rlef = a[--ri];
		}
	}
	cout << ans;
	return 0;
}

