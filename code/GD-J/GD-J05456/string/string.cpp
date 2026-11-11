#include<bits/stdc++.h>
using namespace std;
int n,a[1000005];
char c[100005],y1,y2;
unsigned long long x = 0,ans = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> a[i] >> c[i];
	}
	for(int i = 1;i <= n;++i){
		x += a[i];
	}
	
	for(int k = 1;k <= x / 2;++k){
		int x1 = k;
	for(int i = 1;i <= n;++i){
		if(x1 > a[i]){
			x1 -= a[i];
			continue;
		}else{
			y1 = c[i];
		}
	}
	x1 = k;
	for(int i = i;i <= n;++i){
		if(x1 > a[n + 1 - i]){
			x1 -= a[n + 1 - i];
			continue;
		}else{
			y2 = c[n + 1 - i];
		}
	}
	if(y1 != y2){
		++ans;
	}
	}
	
	cout << ans;
	return 0;
}
