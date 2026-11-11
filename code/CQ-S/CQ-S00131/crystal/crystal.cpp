#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mmax = -1;
bool f = true;
bool cmp(int a,int b){
	return a < b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i > 2){
			if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]){
				f = false;
			}
		}
	}
	if(f){
		if(n == 1){
			cout << 1;
			return 0;
		}else{
			sort(a + 1,a + n + 1,cmp);
			long long x = a[n],t = m,s = 1;
			for(int i = n - 1;i >= 1 && t > 0;i--){
				t -= x - a[i];
				if(t >= 0){
					s++;
				}
			}
			cout << s;
			return 0;
		}
	}
	sort(a + 1,a + n + 1,cmp);
	for(int i = n;i >= 1;i--){
		long long x = a[i],t = m,s = 1;
		for(int j = i - 1;j >= 1 && t > 0;j--){
			t -= x - a[j];
			if(t >= 0){
				s++;
			}
		}
		mmax = max(mmax,s);
	}
	cout << mmax;
	return 0;
}
