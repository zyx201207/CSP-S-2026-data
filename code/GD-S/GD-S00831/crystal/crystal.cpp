#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+50;
int n;
int ans = 0;
long long a[N];
unsigned long long m;
bool check(int x){
	unsigned long long ret = 0;
	int tot = 0;
	for(int i=1;i<=n;i++){
		if(a[i]<x){
			tot ++;
			ret += x-a[i];
		}
	}
	//ans = max(ans ,tot);
	return ret <=m;
}
void bs(){
	
	long long l = a[1], r = a[n];
	while(l+1<r){
		long long mid = (l + r) / 2;
		if(check(mid)) l =mid;
		else r = mid;
	}
	int i;
	for(i=1;i<=n;i++){
		if(m>=l-a[i])ans++, m-=l-a[i];
	}
	//cout << l << endl;
	cout << ans;
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	bs();
	/*
	二分
	二分最大能量值 
	mid
	如果mid<=所需能量值
	 
	*/
	
	return 0;
}
