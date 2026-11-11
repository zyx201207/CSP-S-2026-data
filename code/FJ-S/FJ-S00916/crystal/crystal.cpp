#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int maxRes[100086];
bool cmp(int a,int b){
	return a > b;
}

int main(){
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	ll n;
	ll m;
//	cin >> n >> m;
	fin >> n >> m;
	ll a[n];
	ll w = m;
	
	bool flag1 = false;
	bool flag2 = false; 
	
	fin >> a[0] >> a[1];
//	cin >> a[0] >> a[1];
	ll pianfen = a[0];
	int dir = a[1] - a[0];
//	cout << dir;

	for(int i = 2;i < n;i++){
//		cin >> a[i];
		fin >> a[i];
		if(a[i] != a[0]){
			flag1 = true;
		}
	}
	
	sort(a,a + n);
	int cntSame[100086];
	int cur = a[0];
	
	if(m == 0){
		for(int i = 0,j = 0;i < n;i++){
			if(cur == a[i]){
				cntSame[j]++;
			}else{
				cur = a[i];
				j++;
				cntSame[j]++;
			}
		}
		sort(cntSame,cntSame + n + 1,cmp);
		fout << cntSame[0] << "\n";
//		cout << cntSame[0] << "\n";
		return 0;
	}
	
	for(int i = 2;i < n;i++){
		if(i >= 1 && a[i] - a[i - 1] != dir){
			flag2 = true;
		}
	}
	
	if(!flag1){
//		cout << n;
		fout << n;
		return 0;
	}
	
//	cout << flag2;

	if(!flag2){
//		cout << "0";
		int b = 0;
		for(int i = 1;;i++){
			b += dir * i;
			if(b > m){
				fout << i << "\n";
//				cout << i << "\n";
				return 0;
			}
		}
	}
//	int dirr[100086];
//	dirr[0] = 0;
//	for(int i = 1;i < n;i++){
//		dirr[i] = a[i] - a[i - 1];
//	}
//	int sum;
//	for(int i = 1;i < n;i++){
//		sum = 0;
//		for(int j = 0;j <= i;j++){
//			int d = dirr[j];
//			sum += d; 
//			if(sum > m){
//				maxRes[i] = j - 1;
//			}
//		}
//	}
//	sort(maxRes,maxRes + n,cmp);
//	fout << maxRes[0];
//	for(int i = 0;i < n;i++){
//		int sum = 0;
//		for(int j = 0;j <= i;j++){
//			sum += abs(dirr[j]);
//			if(sum > m){
//				maxRes[i] = j - 1;
//			}
//		}
////	}
//	sort(maxRes,maxRes + n,cmp);
//	cout << maxRes[0];

	ll r = 0;
	ll sp = a[0];
	ll ans = 0;
	ll l = 0;
	
	for(;r < n && l <= r;l++){
//		if(l != 0){
////			sp = sp - a[l];
//			r++;
//			sp += a[r];
//		}
		if(a[r] * (r - l + 1) <= sp + w){
			while(a[r] * (r - l + 1) <= sp + w && r < n){
				r++;
				sp += a[r];
			}
			sp -= a[r - 1];
			r--;
			ans = max(ans,r - l + 1);
		}
	}
	
	fout << ans << "\n";
//	cout << ans <<"\n";
	return 0;
}
