#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500005], c[500005], c2[500005];

bool cmp(long long a, long long b){
	return a <= b;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "r", stdout);
	
	cin >> n >> m;
	a[0] = -0xfffffff;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		c[i] = a[i] - a[i-1];
		c2[i] = c[i];
	}
	
	sort(c2+1,c2+n,cmp);
	swap(c2[n-1], c2[n]);
	
	//不可能合成水晶
	if(n == 1 || c2[1] > m){
		cout << 0;
		return 0;
	}
	
	long long ans=0;
	if(m == 0){ //操作0次 
		for(int i=1;i<=n;i++){
			if(c2[i]==0) ans++;
		}
		cout << ans+1;
		return 0;
	}
	if(m == 1){ //操作1次 
		for(int i=1;i<=n;i++){
			if(c2[i]==0) ans++;
			else if(c2[i]==1){
				ans++;
				cout << ++ans;
				return 0;
			}
		}
		cout << ++ans; 
		return 0;
	}
	else{ 
		long long cnt=0;
		for(int i=1;i<=n;i++){
			if(c2[i]==0) ans++;
			else if(c2[i]==1){
				ans++;
				cnt++;
				cout << ans+cnt;
				return 0;
			}
		}
		cout << ++ans;
		return 0;
	}
	return 0;
}
