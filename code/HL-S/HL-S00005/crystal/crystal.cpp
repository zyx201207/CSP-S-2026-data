#include<bits/stdc++.h>

using namespace std;

long long n,m;
const int N = 5e5 + 5;
long long a[N];
long long cf[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	bool tpA = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != i) tpA = 0;
	}
	
	if(tpA == 1){
		cf[1] = 0;
		for(int i = 2;i <= n;i++){
			cf[i] = a[i - 1]; 
		}
//		for(int i = 1;i <= n;i++){
//			cout << cf[i] << " ";
//		}
//		cout << endl;
//		cout << mop << endl;;
		long long mop = m;
		int i = 1;
		while(mop >= 0){
			if(mop - cf[i] >= 0){
				if(i <= 0){
					mop -= cf[i];
					i++;
				}else{
					cout << n;
					return 0;
				}
			}else{
				cout << i - 1;
				return 0;
			}
//			cout << mop;
		}
	}else{
		cf[1] = 0;
		for(int i = 2;i <= n;i++){
			cf[i] = a[i] - a[i - 1] + cf[i - 1];
		}
//		for(int i = 1;i <= n;i++){
//			cout << cf[i] << ' ';
//		}
		long long mop = m;
		int i = 1;
		while(mop >= 0){
			if(mop - cf[i] >= 0){
				if(i <= n){
					mop -= cf[i];
					i++;
				}else{
					cout << n;
					return 0;
				}
			}else{
				cout << i - 1;
				return 0;
			}
		}
	}
	return 0;
}
/*
5 100
25 30 35 40 45
*/