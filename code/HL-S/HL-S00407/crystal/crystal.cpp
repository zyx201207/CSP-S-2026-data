#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
long long n, m;
int a[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		a[i] += 500;
	}
	int ender = a[n];
	int lefter = a[1];
	sort(a + 1, a + n + 1);
	int cnt = 0, ans = 0;
	int temp = 0;
	int endans = 0;
	for(int j = 1; j <= n; j++){
		ender = a[n];
		while(ender){
			cnt = 0;
			ans = 0;
			for(int i = j; i <= n; i++){
				if(a[i] > ender){
					break; 
				}else{
					cnt += ender - a[i];
					ans++; 
				}
			}
			if(cnt > m){
				ender--;
				continue;
			}else if(cnt <= m){
				ender--;
				endans = max(endans, ans);
			}	
		}	
	}
	cout<<endans;
	return 0;
}