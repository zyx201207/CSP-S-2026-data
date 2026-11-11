//GZ-J00368 贵阳市第三十三中学 叶发睿 
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n, m, a[N];
int ma = INT_MIN; 

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	while(m--){
		for(int i = 1; i <= n; i++){
			if(a[i]&a[i+1] > ma){
				ma = a[i]&a[i+1];
			} 
		}
	} 
	cout << ma;
	return 0;
}
