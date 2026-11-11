#include<bits/stdc++.h>
using namespace std;
int n = 0;
bool f1 = true, f2 = true;
long long m = 0, ans = 0, ansA = 0, ansB = 1;
long long a[500005], c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a+0,a+n);
	//A
	for(int i = 0; i < n-1; i++){
		if(a[i] != a[i+1]) f1 = false;
	}
	if(f1){
		ansA = n;
		cout << ansA;
		return 0;
	} 
	//B
	long long k = a[1] - a[0];
	for(int i = 0; i < n-1; i++){
		if(a[i+1] - a[i] != k) f2 = false;
	}
	if(f2){
		long long sumB = 0, mB = m;
		while(mB >= 0){
			sumB += k;
			mB -= sumB;
			ansB++;
		}
		cout << ansB;
		return 0;
	} 
	//E
	for(int i = 1; i < n; i++){
		c[i-1] = a[i] - a[i-1];
	}
	for(int i = n-1; i > 0; i--){
		long long num = 1, sum = 0, now = m;
		for(int j = i-1; j >= 0; j--){
			sum += c[j];
			now -= sum;
			if(now >= 0){
				num++;
			} 
			
			else break;
		}
		ans = max(ans,num);
	}
	cout << ans;
	return 0;
}
