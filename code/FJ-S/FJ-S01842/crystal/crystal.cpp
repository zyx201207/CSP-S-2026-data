#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[1000000],b[500005],ans = -1;
int cnt(int l,int r){
	return b[r] - b[l - 1];
}
int work(int l,int r,int len){
	if(a[r]*len == (cnt(l,r) + m)){
		return len;
	}
	return -1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = b[i - 1] + a[i];
	} 
	sort(a+1,a+1+n);
	for(int len = 1; len <= n; len++){
		for(int l = 1; l + len -1 <= n; l++){
			int r = l + len -1;
			int k = work(l,r,len);
			if(k == -1) continue;
			ans = max(ans,k);
		}
	}
	cout << ans;
	return 0;
}

