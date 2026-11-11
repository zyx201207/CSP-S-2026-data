#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[600001],n,m;
bool check(int x){
	int cnt = 0;
	int ans = 1e18;
	int l = 1;
	cnt = 0;
	for(int r = 2;r<=n;r++){
//		cout <<r << endl;
		if(r-l+1 > x){
			cnt = cnt-a[r-1]+a[l];
			l++;
		}
		int y = a[r]-a[r-1];
		cnt =cnt + y*(r-l);
		if(r >= x){
			ans = min(ans,cnt);
		}
//		for(int i = l;i<=r;i++){
//			cout << a[i] << " ";
//		}
//		cout << endl << "cnt : " <<cnt << endl;
	}
	return (ans <= m);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int l = 0,r = n;
	while(l < r){
//		cout << l << " " << r << endl;
		int mid = (l+r+1)/2;
		if(check(mid)){
			l = mid;
		}else{
			r = mid-1;
		}
	}
	cout << l << endl;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
