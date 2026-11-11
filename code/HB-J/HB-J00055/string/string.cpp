#include<bits/stdc++.h>
using namespace std;
int times[200005] = {};
char c[200005] = {};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> times[i] >> c[i];
	}
	long long ans = 0;
	int l = 1,r = n;
	while(l<r){
		if(times[l] < times[r]){
			ans += (c[l] != c[r])*times[l];
			times[r] -= times[l];
 			times[l] = 0;
			l ++;
		}
		else if(times[l] > times[r]){
			ans += (c[l] != c[r])*times[r];
			times[l] -= times[r];
			times[r] = 0;
			r --;
		}
		else if(times[l] == times[r]){
			ans += (c[l] != c[r]) * times[r];
			times[r] = 0;
			times[l] = 0;
			l ++;
			r --;
		}
	}
	cout << ans;
}

