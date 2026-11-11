#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5; 
int n,m;
int a[N];
int sum[N];
int l = 0,r,mid;


bool check(int mi){
	for(int i = mi,cnt = 0;i <= n;i ++,cnt ++){
		if(m >= a[i] * mi - (sum[mi] - sum[cnt])) return true;
	}
	return false;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i ++){
//		cout << a[i] << ' ';
		sum[i] = sum[i - 1] + a[i];
	}
	l = 0;
	r = n;
	while(l < r){
		mid = (l + r + 1) >> 1;
		
		if(check(mid)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	cout << l;
	
	return 0;
}

/*
5 5
1 2 4 8 9
*/
